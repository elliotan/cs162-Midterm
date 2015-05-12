///Andrew Elliott
///CS162 Fall 2014
///Final Project


#include <iostream>
#include <string>

using namespace std;

///Class declarations
class Car{    ///abstract class

protected:
    string carName;
    string item1;
    string smell;
public:

    string item2;
    string item3;
    string item4;
    void set_Name(string a)
    {
        carName = a;
    }
    void set_items(string a, string b, string c, string d)
    {
        item1 = a;
        item2 = b;
        item3 = c;
        item4 = d;
    }
    void set_smell(string a)
    {
        smell = a;
    }
    virtual string getCarName(void) = 0;
    virtual string getItem1(void) = 0;
    virtual string getItem2(void) = 0;
    virtual string getItem3(void) = 0;
    virtual string getItem4(void) = 0;
    virtual string getSmell(void) = 0;
    ///Car *carPointer;
    Car *nextCar;
    Car *priorCar;
};

///inherited classes
class Engine : public Car{

public:
    string getCarName(void)
    {
        return carName;
    }
    string getItem1(void)
    {
        return item1;
    }
    string getItem2(void)
    {
        return item2;
    }
    string getItem3(void)
    {
        return item3;
    }
    string getItem4(void)
    {
        return item4;
    }
    string getSmell(void)
    {
        return smell;
    }
};

class Diner : public Car{

public:
    string getCarName(void)
    {
        return carName;
    }
    string getItem1(void)
    {
        return item1;
    }
    string getItem2(void)
    {
        return item2;
    }
    string getItem3(void)
    {
        return item3;
    }
    string getItem4(void)
    {
        return item4;
    }
    string getSmell(void)
    {
        return smell;
    }
};

class Passenger : public Car{

public:
    string getCarName(void)
    {
        return carName;
    }
    string getItem1(void)
    {
        return item1;
    }
    string getItem2(void)
    {
        return item2;
    }
    string getItem3(void)
    {
        return item3;
    }
    string getItem4(void)
    {
        return item4;
    }
    string getSmell(void)
    {
        return smell;
    }
};

///iterator class
class carIterator{

public:
    Car * iter;
    void next()
    {
        iter = iter->nextCar;
    }
    void prior()
    {
        iter = iter->priorCar;
    }
};

int main()
{
    char playAgain = 'y';
    do{
        ///instantiate classes for 10 compartments and iterator
        Diner d;
        Engine e;
        Passenger p1, p2, p3, p4, p5, p6, p7, p8;
        carIterator carIt;
        carIt.iter = &e;

        ///assign values to classes
        d.set_Name("Diner Car (2 of 10)");
        d.set_items("Cranky lunch lady", "Frozen Burrito", "Moldy Quiche", "12lb Block of Cheese");
        e.set_Name("Engine Car (1 of 10)");
        e.set_items("Train Control Panel", "Unconscious Conductor", "Bag of Peanuts", "puddle of drool");
        p1.set_Name("Passenger Car 1 (3 of 10)");
        p1.set_items("Coffee Cup", "Tootsie Roll", "Set of Headphones", "Homeless person");
        p2.set_Name("Passenger Car 2 (4 of 10)");
        p2.set_items("Empty Wallet", "Pair of mismatched socks", "Candle", "Stinky Hippy");
        p3.set_Name("Passenger Car 3 (5 of 10)");
        p3.set_items("Badass Guitar", "10 Gallon Bucket of Bleach", "Ketchup Packet", "Laptop");
        p4.set_Name("Passenger Car 4 (6 of 10)");
        p4.set_items("Pack of Antihistamine", "Lanyard", "Table", "Saddam Hussein bust");
        p5.set_Name("Passenger Car 5 (7 of 10)");
        p5.set_items("Pack of cigarettes", "Backpack", "pile of toenail clippings", "Blankie");
        p6.set_Name("Passenger Car 6 (8 of 10)");
        p6.set_items("Hotdog", "model train", "whoopie cushion", "random Dictator");
        p7.set_Name("Passenger Car 7 (9 of 10)");
        p7.set_items("iPhone", "Twinkie", "Donut", "Spoon");
        p8.set_Name("Passenger Car 8 (10 of 10)");
        p8.set_items("Cold, refreshing Diet Coke", "Stray cat", "Stray dog", "Stray walrus");
        d.set_smell("Greasy Food");
        e.set_smell("Gasoline");
        p1.set_smell("a Homeless Person");
        p2.set_smell("a Phish Concert");
        p3.set_smell("a landromat");
        p4.set_smell("the city of Baghdad");
        p5.set_smell("Smoke");
        p6.set_smell("a Baseball game");
        p7.set_smell("a Bakery");
        p8.set_smell("a soft drink");
        int userInput;
        string backpack[3];
        int packCounter = 0;

        e.priorCar = NULL;     ///manual connection of the compartments
        e.nextCar = &d;
        d.priorCar = &e;
        d.nextCar = &p1;
        p1.priorCar = &d;
        p1.nextCar = &p2;
        p2.priorCar = &p1;
        p2.nextCar = &p3;
        p3.priorCar = &p2;
        p3.nextCar = &p4;
        p4.priorCar = &p3;
        p4.nextCar = &p5;
        p5.priorCar = &p4;
        p5.nextCar = &p6;
        p6.priorCar = &p5;
        p6.nextCar = &p7;
        p7.priorCar = &p6;
        p7.nextCar = &p8;
        p8.priorCar = &p7;
        p8.nextCar = NULL;

        Car *pointer = NULL;
        pointer = &e;

        cout << "*****  TRAIN ESCAPE  *****" << endl << endl;
        cout << "You wake up in a daze in the Engine Car of a speeding train . . " << endl;
        cout << "The conductor is laying unconscious with his hand on the throttle!" << endl;
        cout << "Suddenly, the conductor opens his eyes . . . " << endl;
        cout << "\"Help...Me\" he sputters" << endl;
        cout << "\"I have a peanut allergy and I ate too many Planters\" " << endl;
        cout << "\"Also, I could really use a cool, refreshing Diet Coke\"" << endl;
        cout << "\"Oh and also, a Frozen Burrito\"" << endl << endl;

        cout << "Distressed by the conductor's utter lack of self-preservation and his absurd " << endl;
        cout << "notion that you are some sort of delivery boy, you begin your search of " << endl;
        cout << "the train to find his desired items." << endl << endl;

        cout << "Press 1 to continue..." << endl;
        cin >> userInput;
        while (userInput != 1)
        {
            cout << "Press 1 ";
            cin >> userInput;
        }
        for (int i = 0; i < 10; i++)  ///clears screen a bit
        {
            cout << endl;
        }
        cout << "You need to bring him Antihistamine, a Cold, refreshing Diet Coke, and a Frozen Burrito" << endl << endl;

        cout << "Traverse the train and pick up items using the 10-key pad!" << endl << endl;

        cout << "Your backpack only holds 3 items, so choose which items to pick up carefully!" << endl << endl;
        menuSelect:
        ///main game loop - stops executing after 3 items are added to the user backpack
        while ( packCounter < 3)
        {
            cout << "You are currently in the " << carIt.iter -> getCarName() << "." << endl;
            cout << "In this car, you can't help but notice that it smells like " << carIt.iter -> getSmell() << "." << endl;
            cout << "In the car, you see: " << endl;
            cout << "A " << carIt.iter -> getItem1() << endl;
            cout << "A " << carIt.iter -> getItem2() << endl;
            cout << "A " << carIt.iter -> getItem3() << endl;
            cout << "A " << carIt.iter -> getItem4() << endl;
            cout << endl << "Please use one of the following commands: " << endl;
            cout << "1 - pick up the " << carIt.iter -> getItem1() << endl;
            cout << "2 - pick up the " << carIt.iter -> item2 << endl;
            cout << "3 - pick up the " << carIt.iter -> item3 << endl;
            cout << "4 - pick up the " << carIt.iter -> item4 << endl;
            cout << "5 - move to the prior car" << endl;
            cout << "6 - move to the next car" << endl;
            cout << "7 - see the answer key" << endl;
            cout << "8 - QUIT" << endl;
            cin >> userInput;

            switch(userInput){
                case 1:
                {
                    backpack[packCounter] = carIt.iter ->getItem1();
                    cout << endl << "You picked up a " << carIt.iter->getItem1() << endl << endl;
                    packCounter++;
                    goto menuSelect;
                }
                case 2:
                {
                    backpack[packCounter] = carIt.iter ->getItem2();
                    cout << endl << "You picked up a " << carIt.iter->getItem2() << endl << endl;
                    packCounter++;
                    goto menuSelect;
                }
                case 3:
                {
                    backpack[packCounter] = carIt.iter ->getItem3();
                    cout << endl << "You picked up a " << carIt.iter->getItem3() << endl << endl;
                    packCounter++;
                    goto menuSelect;
                }
                case 4:
                {
                    backpack[packCounter] = carIt.iter ->getItem4();
                    cout << endl << "You picked up a " << carIt.iter->getItem4() << endl << endl;
                    packCounter++;
                    goto menuSelect;
                }
                case 5:
                {
                    if(carIt.iter-> getCarName() == "Engine Car (1 of 10)") ///checks if the user is in the engine room
                    {
                        cout << endl << "You can't go that way - You'll fall in front of the train and die!" << endl << endl;
                        goto menuSelect;
                    }
                    carIt.prior();  ///move iterator to previous car
                    break;
                }
                case 6:
                {
                    if(carIt.iter-> getCarName() == "Passenger Car 8 (10 of 10)")  ///checks if user is in the caboose
                    {
                        cout << endl << "You can't go that way - You'll fall off the back and die!" << endl << endl;
                        goto menuSelect;
                    }
                    carIt.next(); ///move iterator to next car
                    break;
                }
                case 7:   ///answer key
                {
                    cout << "The frozen burrito is in the diner car (2 of 10)" << endl;
                    cout << "The Antihistamine is in passenger car 4 (6 of 10)" << endl;
                    cout << "The Cool, refreshing Diet Coke is in Passenger car 8 (10 of 10)" << endl << endl;
                    break;
                }
                case 8:
                {
                    cout << "Goodbye quitter! " << endl;
                    return 0;
                }
                default:
                {
                    cout << "Invalid entry" << endl;
                    goto menuSelect;
                }
            }

        }
        for(int i = 0; i<50;i++)
        {
            cout << endl;
        }
        cout << "Your backpack is now full!" << endl << endl;
        cout << "You return to the Engine car with your backpack containing: " << endl;
        string burrito = "Frozen Burrito";
        string anti = "Antihistamine";
        string CRDC = "Cool, refreshing Diet Coke";
        bool win1 = false;
        bool win2 = false;
        bool win3 = false;
        for (int i= 0; i < 3; i++)
        {
            cout << "a " << backpack[i] << endl;
            ///checks if items in the backpack match the items the conductor needs
            if(backpack[i] == "Frozen Burrito")
            {
                win1 = true;
            }
            if(backpack[i] == "Pack of Antihistamine")
            {
                win2 = true;
            }
            if(backpack[i] == "Cold, refreshing Diet Coke")
            {
                win3 = true;
            }
        }
        if((win1 == true) && (win2 == true) && (win3 == true))
        {
            int dropHim;
            cout << endl << "You slowly feed the rock hard " << burrito << " to the conductor" << endl;
            cout << "He chews it slowly, and motions for the " << CRDC << endl;
            cout << "You shove the unopened pack of " << anti << " down his throat" << endl;
            cout << "He stands up and cracks the lid of the " << CRDC << endl;
            cout << "He takes a long swig and stops the runaway train safely" << endl;
            cout << endl << "You ask for a sip of the " << CRDC << ". He declines." << endl;
            cout << "Press 1 to drop this idiot " << endl;
            cin >> dropHim;
            while (dropHim != 1)
            {
                cout << "He took your " << CRDC << ". You MUST press 1 to drop this fool ";
                cin >> dropHim;
            }
            cout << "You drop kick him in the face.  He falls to the floor." << endl;
            cout << "Luckily, you catch the " << CRDC << " before it hits the ground" << endl;
            cout <<"                    z$$$$$.                                           " << endl;
            cout <<"                 $$$$$$$$$$$                                          " << endl;
            cout <<"                $$$$$$**$$$$               eeer                       " << endl;
            cout <<"    YOU        $$$$$%   '$$$               $$$F                       " << endl;
            cout <<"    WIN!      4$$$$P     *$$               $$$F                       " << endl;
            cout <<"              $$$$$      '$$    .ee.       $$$F            ..e.       " << endl;
            cout <<"    HAVE      $$$$$       ""   .$$$$$$b     $$$F 4$$$$$$   $$$$$$c     " << endl;
            cout <<"     A       4$$$$F           4$$$""$$$$    $$$F '*$$$$*  $$$P$$$$L    " << endl;
            cout <<"             4$$$$F         .$$$F  ^$$$b   $$$F  J$$$   $$$$  ^$$$.   " << endl;
            cout <<"             4$$$$F         d$$$    $$$$   $$$F J$$P   .$$$F   $$$$   " << endl;
            cout <<"             4$$$$F         $$$$    3$$$F  $$$FJ$$P    4$$$$   $$$$   " << endl;
            cout <<"             4$$$$F        4$$$$    4$$$$  $$$$$$$r    $$$$$$$$$$$$   " << endl;
            cout <<"             4$$$$$        4$$$$    4$$$$  $$$$$$$$    $$$$********   " << endl;
            cout <<"              $$$$$        4$$$$    4$$$F  $$$F4$$$b   *$$$r          " << endl;
            cout <<"              3$$$$F       d$$$$    $$$$$  $$$F *$$$F  4$$$L     .    " << endl;
            cout <<"               $$$$$.     d$$$$$.   $$$$   $$$F  $$$$.  $$$$    z$P   " << endl;
            cout <<"                $$$$$e..d$$$$$$$b  4$$$$  J$$$L  '$$$$  '$$$b..d$$    " << endl;
            cout <<"                 *$$$$$$$$$  ^$$$be$$$$  $$$$$$$  3$$$$F '$$$$$$$'    " << endl;
            cout <<"                  ^*$$$$P$     *$$$$*    $$$$$$$   $$$$F  ^*$$$''     " << endl;

        }
        else
        {
            int drinkCoke;
            cout << endl << "The conductor gasps when he sees that you brought him the wrong items" << endl;
            cout << "He breathes his last breath of air and dies." << endl;
            cout << "You see a cliff fast approaching...what do you do??" << endl;
            cout << "1 - Have a sip of the " << CRDC << endl;
            cin >> drinkCoke;
            while(drinkCoke != 1)
            {
                cout << "You must drink the coke! Press 1 ";
                cin >> drinkCoke;
            }
            cout << endl << "Sadly, you fall screaming to a flaming death, but not before enjoying a " << CRDC << "!" << endl;
            cout <<"                    z$$$$$.                                           " << endl;
            cout <<"                 $$$$$$$$$$$                                          " << endl;
            cout <<"                $$$$$$**$$$$               eeer                       " << endl;
            cout <<"    YOU        $$$$$%   '$$$               $$$F                       " << endl;
            cout <<"    LOST!     4$$$$P     *$$               $$$F                       " << endl;
            cout <<"              $$$$$      '$$    .ee.       $$$F            ..e.       " << endl;
            cout <<"    HAVE      $$$$$       ""   .$$$$$$b     $$$F 4$$$$$$   $$$$$$c     " << endl;
            cout <<"     A       4$$$$F           4$$$""$$$$    $$$F '*$$$$*  $$$P$$$$L    " << endl;
            cout <<"             4$$$$F         .$$$F  ^$$$b   $$$F  J$$$   $$$$  ^$$$.   " << endl;
            cout <<"             4$$$$F         d$$$    $$$$   $$$F J$$P   .$$$F   $$$$   " << endl;
            cout <<"             4$$$$F         $$$$    3$$$F  $$$FJ$$P    4$$$$   $$$$   " << endl;
            cout <<"             4$$$$F        4$$$$    4$$$$  $$$$$$$r    $$$$$$$$$$$$   " << endl;
            cout <<"             4$$$$$        4$$$$    4$$$$  $$$$$$$$    $$$$********   " << endl;
            cout <<"              $$$$$        4$$$$    4$$$F  $$$F4$$$b   *$$$r          " << endl;
            cout <<"              3$$$$F       d$$$$    $$$$$  $$$F *$$$F  4$$$L     .    " << endl;
            cout <<"               $$$$$.     d$$$$$.   $$$$   $$$F  $$$$.  $$$$    z$P   " << endl;
            cout <<"                $$$$$e..d$$$$$$$b  4$$$$  J$$$L  '$$$$  '$$$b..d$$    " << endl;
            cout <<"                 *$$$$$$$$$  ^$$$be$$$$  $$$$$$$  3$$$$F '$$$$$$$'    " << endl;
            cout <<"                  ^*$$$$P$     *$$$$*    $$$$$$$   $$$$F  ^*$$$''     " << endl;
        }
    cout << "Play again? (y/n) ";
    cin >> playAgain;
    }while (playAgain == 'y');

    return 0;
}

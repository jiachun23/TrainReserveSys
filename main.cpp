#include <iostream>
#include <typeinfo>
#include<fstream>

using namespace std;

void getTrainDeparture_Time()
void getTrainArrival_Time()
void getTrainMeal()
abstract start();

void scheduleMelakaToThai(){ //Display schedule from Melaka to Thailand
    cout << "Melaka -> Thai" << endl;
    cout << "1) 8:00 am to 1:00 pm" << endl;
    cout << "2) 12:00 pm to 5:00 pm" << endl;
    cout << "3) 4:00 pm to 9:00 pm" << endl;
    cout << "4) 8:00 pm to 1:00 am" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleThaiToMelaka(){ //Display schedule from Thailand to Melaka
    cout << "Thai -> Melaka" << endl;
    cout << "1)8:00 am to 1:00 pm" << endl;
    cout << "2) 12:00 pm to 5:00 pm" << endl;
    cout << "3) 4:00 pm to 9:00 pm" << endl;
    cout << "4) 8:00 pm to 1:00 am" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleMelakaToSg(){ //Display schedule from Melaka to Singapore
    cout << "Melaka -> Singapore" << endl;
    cout << "1) 9:00 am to 11:00 am" << endl;
    cout << "2) 11:00 am to 1:00 pm" << endl;
    cout << "3) 3:00 pm to 5:00 pm" << endl;
    cout << "4) 5:00 pm to 7:00 pm" << endl;
    cout << "5) 7:00 pm to 9:00 pm" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleSgToMelaka(){ //Display schedule from Singapore to Melaka
    cout << "Singapore -> Melaka" << endl;
    cout << "1) 9:00 am to 11:00 am" << endl;
    cout << "2) 11:00 am to 1:00 pm" << endl;
    cout << "3) 3:00 pm to 5:00 pm" << endl;
    cout << "4) 5:00 pm to 7:00 pm" << endl;
    cout << "5) 7:00 pm to 9:00 pm" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleSgToThai(){ //Display schedule from Singapore to Thailand
    cout << "Singapore -> Thai" << endl;
    cout << "1) 6:30 am to 2:30 pm" << endl;
    cout << "2) 12:30 pm to 10:00 pm" << endl;
    cout << "3) 7:30 pm to 3:00 am" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleThaiToSg(){ //Display schedule from Thailand to Singapore
    cout << "Thai -> Singapore" << endl;
    cout << "1) 6:30 am to 2:30 pm" << endl;
    cout << "2) 12:30 pm to 10:00 pm" << endl;
    cout << "3) 7:30 pm to 3:00 am" << endl;
    cout << "Please select the schedule" << endl;
}

void getMealMenu(){
    cout<<"Select the available meals:"<<endl;
    cout<<endl;
    cout<<"1) Nasi Lemak                    RM3.00"<<endl;
    cout<<"2) Chicken Chop & Fries          RM9.00"<<endl;
    cout<<"3) Spaghetti Bolognese           RM5.00"<<endl;
    cout<<"4) Fish and Chips                RM10.00"<<endl;
    cout<<"5) Char Kuey Teow                RM5.00"<<endl;
    cout<<"6) Roti Canai (2x)               RM3.00"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<endl;
    cout<<"Vegetarian Foods:"<<endl;
    cout<<endl;
    cout<<"7) Vegan Burger & Fries          RM4.00"<<endl;
    cout<<"8) Mushroom Soup                 RM4.00"<<endl;
    cout<<"9) Salad Bowl                    RM5.00"<<endl;
    cout<<"10) Pan Mee Soup with Egg         RM6.00"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<endl;
    cout<<"Non-Halal Foods:"<<endl;
    cout<<endl;
    cout<<"11) Pork Burger & Fries           RM12.00"<<endl;
    cout<<"12) Roasted Pork Rice             RM5.00"<<endl;
}

void getDrinkMenu(){
    cout<<"Select the available drinks:"<<endl;
    cout<<endl;
    cout<<"Soft drinks:"<<endl;
    cout<<endl;
    cout<<"1) Coca-Cola                     RM2.80"<<endl;
    cout<<"2) 100 Plus                      RM2.80"<<endl;
    cout<<"3) Mountain Dew                  RM2.80"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<endl;
    cout<<"Hot Beverages:"<<endl;
    cout<<endl;
    cout<<"4) Coffee                        RM2.00"<<endl;
    cout<<"5) Tea                           RM1.50"<<endl;
    cout<<"6) Cappuccino                    RM3.00"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<endl;
    cout<<"Milkshakes:"<<endl;
    cout<<endl;
    cout<<"7) Chocolate Milkshake           RM6.50"<<endl;
    cout<<"8) Strawberry Milkshake          RM6.50"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<endl;
    cout<<"Alcoholic Drinks:"<<endl;
    cout<<endl;
    cout<<"9) Carlsberg         (1 pint)    RM9.00"<<endl;
    cout<<"10) Tiger             (1 pint)    RM9.00"<<endl;
    cout<<"11) Kronenburg 1664   (1 pint)    RM10.00"<<endl;

}

void drinkSelect(){
    cin >> drinkChoice;
    switch (drinkChoice){
    case 0:
        break;
    case 1:
        orderTotal += 2.8;
        cout << "Coca-Cola has been added to your meal" << endl;
        break;
    case 2:
        orderTotal += 2.8;
        cout << "100 Plus has been added to your meal" << endl;
        break;
    case 3:
        orderTotal += 2.8;
        cout << "Mountain Dew  has been added to your meal" << endl;
        break;
    case 4:
        orderTotal += 2;
        cout << "Coffee has been added to your meal" << endl;
        break;
    case 5:
        orderTotal += 1.5;
        cout << "Tea  has been added to your meal" << endl;
        break;
    case 6:
        orderTotal += 3;
        cout << "Cappuccino has been added to your meal" << endl;
        break;
    case 7:
        orderTotal += 6.5;
        cout << "Chocolate Milkshakes has been added to your meal" << endl;
        break;
    case 8:
        orderTotal += 6.5;
        cout << "Strawberry Milkshake has been added to your meal" << endl;
        break;
    case 9:
        orderTotal += 9;
        cout << "Carlsberg  (1 pint) has been added to your meal" << endl;
        break;
    case 10:
        orderTotal += 9;
        cout << "Tiger (1 pint)has been added to your meal" << endl;
        break;
    case 11:
        orderTotal += 10;
        cout << "Kronenburg 1664 (1 pint) has been added to your meal" << endl;
        break;
    default:
        cout << "Choice not found ! Please enter again" << endl;
        break;
    }
}

void mealSelect(){
    cin >> mealChoice;
    switch (mealChoice){
    case 0:
        break;
    case 1:
        orderTotal += 3;
        cout << "Nasi Lemak has been added to your meal" << endl;
        break;
    case 2:
        orderTotal += 9;
        cout << "Chicken Chop & Fries   has been added to your meal" << endl;
        break;
    case 3:
        orderTotal += 5;
        cout << "Spaghetti Bolognese has been added to your meal" << endl;
        break;
    case 4:
        orderTotal += 10;
        cout << "Fish and Chips has been added to your meal" << endl;
        break;
    case 5:
        orderTotal += 5;
        cout << "Char Kuey Teow has been added to your meal" << endl;
        break;
    case 6:
        orderTotal += 3;
        cout << "Roti Canai (2x) has been added to your meal" << endl;
        break;
    case 7:
        orderTotal += 4;
        cout << "Vegan Burgers and Fries has been added to your meal" << endl;
        break;
    case 8:
        orderTotal += 4;
        cout << "Mushroom Soup has been added to your meal" << endl;
        break;
    case 9:
        orderTotal += 5;
        cout << "Salad Bowl has been added to your meal" << endl;
        break;
    case 10:
        orderTotal += 6;
        cout << "Pan Mee Soup with Egg has been added to your meal" << endl;
        break;
    case 11:
        orderTotal += 12;
        cout << "Pork Burger & Fries has been added to your meal" << endl;
        break;
    case 12:
        orderTotal += 5;
        cout << "Roasted Pork Rice has been added to your meal" << endl;
        break;
    default :
        cout << "Choice not found ! Please enter again" << endl;
        break;
    }
}

void getBookingList(){
    cout<< "Departure\tDestination\t\tClass Type\t\tPrice" << endl;
    cout<< "Melaka\t\tSingapore\t\tEconomy\t\t\tRM25" << endl;
    cout<< "\t\tSingapore\t\tBusiness\t\tRM45" << endl;
    cout<< "\t\tThai\t\t\tEconomy\t\t\tRM35" << endl;
    cout<< "\t\tThai\t\t\tBusiness\t\tRM65" << endl;
    cout<< "Singapore\tMelaka\t\t\tEconomy\t\t\tRM25" << endl;
    cout<< "\t\tMelaka\t\t\tBusiness\t\tRM45" << endl;
    cout<< "\t\tThai\t\t\tEconomy\t\t\tRM55" << endl;
    cout<< "\t\tThai\t\t\tBusiness\t\tRM85" << endl;
    cout<< "Thai\t\tMelaka\t\t\tEconomy\t\t\tRM35" << endl;
    cout<< "\t\tMelaka\t\t\tBusiness\t\tRM65" << endl;
    cout<< "\t\tSingapore\t\tEconomy\t\t\tRM55" << endl;
    cout<< "\t\tSingapore\t\tBusiness\t\tRM85" << endl;
}

void getTrainDeparture(){

    cout << "Train tickets available from: \n"
    cout << "1. Melaka\n";
    cout << "2. Singapore\n";
    cout << "3. Thailand\n";

}


void getTrainDestination(){

    cout << "Train tickets available to: \n"
    cout << "1. Melaka\n";
    cout << "2. Singapore\n";
    cout << "3. Thailand\n";

}

class Train {
static int trainAmount = 0;
private int trainID;

public:
    Train();
    ~Train();

    bool isEmpty();
    void enqueue(Passenger& newPassenger);
    void dequeue();
    PassengerType getFront();

private:
    struct QueueNode{

    PassengerType passenger;
    QueueNode* next;
    };

    QueueNode* backPtr;
    QueueNode* frontPtr;

Train::Train() : backPtr(NULL), frontPtr(NULL){}

Train::~Train(){
    while (!isEmpty())
    dequeue();
}
bool Train::isEmpty(){
    return backPtr == NULL;
}

void Train::enqueue(Passenger& newPassenger){

    QueueNode* newNodePtr = new QueueNode;

    newNodePtr -> passenger = Passenger.passengerID;
    newNodePtr -> next = NULL;

    if (isEmpty())
        frontPtr = newNodePtr;
    else
        backPtr -> next = newNodePtr;

    backPtr = newNodePtr;

}

void Train::dequeue()
{
    if (isEmpty()) {
        cout << "Dequeue: Queue is empty." << endl;
        return;
    }

    else {

        QueueNode* tempPtr = frontPtr;
        if (frontPtr == backPtr)
            backPtr = NULL;
        frontPtr = frontPtr -> next;
        tempPtr -> next = NULL;
        delete tempPtr;
    }
}

int Train::getFront()
{
    if (isEmpty()) {
        cout << "Dequeue: Queue is empty!" << endl;
        return;
    }
    else
        return frontPtr -> passenger;
}


    void getTrainID(){

        trainID = trainAmount;
        cout << "The train ID of " << Train << " is " << trainID << endl;
    }


    void getTrainTicket_Fee()
    void getTrainSeating()
    void getClassType()


};


class Passenger {
static int passengerID = 0;
static int banIndex = 0;
private string name;
private string phoneNum;
private string passengerIC;
private string banList[];

Passenger(string name, string phoneNum, string passengerIC){
    passengerID++;
    this.name = name;
    this.phoneNum = phoneNum;
    this.passengerIC = passengerIC;
}

void getName()
void getPhoneNum()
void getPassengerIC()
void getAmount_Ticket()
void getBookingID()
void showBooking()
void deleteBooking()
void checkBan_List()

void banPassenger(string IC){
    banList[banIndex] = IC;
    banIndex++;
}

double Total_BookingFee()


};



class Calender {

void getDay()


void getMonth()


void getYear()

};

int main()
{

    Train ML01, ML02, ML03, ML04;
    cout<< "Welcome to the Train Reservation System!" << endl;
    getTrainDeparture(); // Departure list choice
    cout<< "Please choose your departure point(From Point)" << endl;
    cin>> departChoice; // Choose departure point

    while (departChoice != 1 || 2 || 3){ //Error check for departChoice
        cout << "Invalid input, choices are 1,2,3. Please try again. ";
        cin>> departChoice;
    }

    getTrainDestination();
    cout<< "Please choose your destination point(To Point)" << endl;
    cin>> destinationChoice; //Choose destination point

    while (destinationChoice != 1 || 2 || 3){ //Error check for destinationChoice
        cout << "Invalid input, choices are 1,2,3. Please try again. ";
        cin>> destinationChoice;
    }

    if(departChoice == 1){ //depart from Melaka

        if(destinationChoice == departChoice){//Error
            cout << "Error! Your departure point cannot be your destination point. Please try again." << endl;
            start(); //Start from beginning
        }
        else
            getBookingList();
            if(destinationChoice == 2){//from Melaka to Singapore

                cout << "Please enter your class type ( Economy / Business )" << endl;
                cin >> classType;
                cout << "Please enter the number of tickets you would like to reserve" << endl;
                cin >> ticketAmount;
                switch (classType){
                case Economy : case economy :
                    ticketPrice = 25 * ticketAmount;
                    break;
                case Business : business :
                    ticketPrice = 45 * ticketAmount;
                    break;
                default :
                    cout << "Error! Class type not detected please enter in the following format" << endl;
                    cout << "eg : Economy , economy , Business , business" << endl;
                    break;
                }
                scheduleMelakaToSg();
                cin >> scheduleChoice ;
            }
            elseif(destinationChoice == 3){//from Melaka to Thai
                cout << "Please enter your class type ( Economy / Business )" << endl;
                cin >> classType;
                cout << "Please enter the number of tickets you would like to reserve" << endl;
                cin >> ticketAmount;
                switch (classType){
                case Economy : case economy :
                    ticketPrice = 35 * ticketAmount;
                    break;
                case Business : business :
                    ticketPrice = 65 * ticketAmount;
                    break;
                default :
                    cout << "Error! Class type not detected please enter in the following format" << endl;
                    cout << "eg : Economy , economy , Business , business" << endl;
                    break;
                }
                scheduleMelakaToThai();
                cin >> scheduleChoice ;
            }

    }
    elseif(departChoice == 2){ //depart from Singapore

        if(destinationChoice == departChoice){//Error
            cout << "Error! Your departure point cannot be your destination point. Please try again." << endl;
            start(); //Start from beginning
        }
        else
            getBookingList();
            elseif(destinationChoice == 1){//from Singapore to Melaka
                cout << "Please enter your class type ( Economy / Business )" << endl;
                cin >> classType;
                cout << "Please enter the number of tickets you would like to reserve" << endl;
                cin >> ticketAmount;
                switch (classType){
                case Economy : case economy :
                    ticketPrice = 25 * ticketAmount;
                    break;
                case Business : business :
                    ticketPrice = 45 * ticketAmount;
                    break;
                default :
                    cout << "Error! Class type not detected please enter in the following format" << endl;
                    cout << "eg : Economy , economy , Business , business" << endl;
                    break;
                }
                scheduleSgToMelaka();
                cin >> scheduleChoice ;
            }
            elseif(destinationChoice == 3){//from Singapore to Thailand
                cout << "Please enter your class type ( Economy / Business )" << endl;
                cin >> classType;
                cout << "Please enter the number of tickets you would like to reserve" << endl;
                cin >> ticketAmount;
                switch (classType){
                case Economy : case economy :
                    ticketPrice = 55 * ticketAmount;
                    break;
                case Business : business :
                    ticketPrice = 85 * ticketAmount;
                    break;
                default :
                    cout << "Error! Class type not detected please enter in the following format" << endl;
                    cout << "eg : Economy , economy , Business , business" << endl;
                    break;
                }
                scheduleSgToThai();
                cin >> scheduleChoice ;
            }

    }
    elseif(departChoice == 3){//depart from Thai

        if(destinationChoice == departChoice){//Error
            cout << "Error! Your departure point cannot be your destination point. Please try again." << endl;
            start(); //Start from beginning
        }
        else
            getBookingList();
            if(destinationChoice == 1){//from Thai to Melaka
                cout << "Please enter your class type ( Economy / Business )" << endl;
                cin >> classType;
                cout << "Please enter the number of tickets you would like to reserve" << endl;
                cin >> ticketAmount;
                switch (classType){
                case Economy : case economy :
                    ticketPrice = 35 * ticketAmount;
                    break;
                case Business : business :
                    ticketPrice = 65 * ticketAmount;
                    break;
                default :
                    cout << "Error! Class type not detected please enter in the following format" << endl;
                    cout << "eg : Economy , economy , Business , business" << endl;
                    break;
                }
                scheduleThaiToMelaka();
                cin >> scheduleChoice ;
            }
            elseif(destinationChoice == 2){//from Thai to Singapore
                cout << "Please enter your class type ( Economy / Business )" << endl;
                cin >> classType;
                cout << "Please enter the number of tickets you would like to reserve" << endl;
                cin >> ticketAmount;
                switch (classType){
                case Economy : case economy :
                    ticketPrice = 55 * ticketAmount;
                    break;
                case Business : business :
                    ticketPrice = 85 * ticketAmount;
                    break;
                default :
                    cout << "Error! Class type not detected please enter in the following format" << endl;
                    cout << "eg : Economy , economy , Business , business" << endl;
                    break;
                }
                scheduleThaiToSg();
                cin >> scheduleChoice ;
            }


    }

    cout << "Would you like to order meals or drinks ?" << endl;
    cin >> orderChoice;
    switch (orderChoice){
    case Y : case y : case Yes : case yes :
        getMealMenu();
        cout << "Please enter the number of the meal that you would like to order (Type '0' to exit)" << endl;
        do{
            mealSelect();
        }while(mealChoice!=0);

        getDrinkMenu();
        cout << "Please enter the number of the drink that you would like to order (Type '0' to exit)" << endl;
        do{
            drinkSelect();
        }while(drinkChoice!=0);

        cout << "Your food and drink total is: RM " << orderTotal << endl;
        break;

    case N : case n : case No : case no :
        orderTotal = 0;
        break;

    default :
        cout << "Invalid choice, please enter again" << endl;
        break;
    }


    ofstream outFile("record.txt", ios::app);
    for(int i = 0; i< ticketAmount; i++){
        cout<< "Please enter your name (e.g EricaWongPeiWen): " << endl;
        getline (cin, name);
        outFile << "\n" << name << " ";
        cout<< "Please enter your phone number" << endl;
        getline (cin, phoneNum);
        outFile << phoneNum << " ";
        cout<< "Please enter your IC number" << endl;
        getline (cin, passengerIC);
        outFile << passengerIC << " ";

        for(int i = 0; i<banList.length(); i++){ // Check if passenger is banned or not
            if(passengerIC==banList(i)){
                cout<< "Unable to reserve tickets. You have been banned by the system for bad conducts" << endl;
            }
            else continue;
        }
    }

    orderTotal += ticketPrice;
    cout << "The total amount you have to pay is RM " << orderTotal << endl;








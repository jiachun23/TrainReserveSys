#include <iostream>
#include <typeinfo>
#include<fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <vector>
#include "login.h"
#include "login.cpp"
#include "radixSort.cpp"

using namespace std;

int departChoice, destinationChoice, classType, amountTicket, assignedTrain, scheduleChoice, mealChoice, drinkChoice, containerNo, passengerNo, passengerIC, newPassIC, sortSize, sortChoice;
double ticketPrice, orderTotal;
char orderChoice;
string name, phoneNum, newPassName, newPhoneNum, scheduleTime;
bool seatsAvailable, passengerFound, passengerAdded, passengerBanned, emptyList ;
const int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string monthName[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int departDate,returnDate,departMonth,returnMonth,monthStatus=0,status=0;
int arr[100]={0};


///////////////////////////////////////////////////
void static printCalendar(){

cout << "\n\n-----------Plan Your Trip!--------------\n\n";
cout << "------------Viewing Calendar------------\n";
cout << "----------------2019--------------------\n\n";

    int wday = 3; //blank space for decoration like  31 last month , 3 digit blank and leading 1 to next month
    for (int month = 0; month < 12; month++) {

        cout<<monthName[month]<<"\n"; //Calling the month name from array and continue loop
        cout<<setw(7)<<"Sun"<<setw(7)<<"Monday"<<setw(7)<<"Tue"<<setw(7)<<"Wed"<<setw(7)<<"Thur"<<setw(7)<<"Fri"<<setw(7)<<"Sat\n"; //day name and number not same allign, need to use this code in order to same allignment
        for (int i = 0; i < wday; ++i)
            cout <<setw(7)<<" "; //set must be same as above or else the allignment will not be same
        // Print this month's calendar

        for (int mday = 0; mday < monthDays[month]; ++mday, ++wday) { //this loop is to follow previous and next month
            if (wday == 7) {                    //if got 7 days, proceed next number
                cout << '\n';
                wday = 0;
            }
            cout << setw(7) << mday + 1;        //increase one by one
        }
        // Set up for the next month
        if (wday != 7) {
            cout << '\n';
        }
        cout << endl;
    }

    cout<<"\n\n------------DEPARTURE DATE------------\n\n";
    //int departDate,returnDate,departMonth,returnMonth,monthStatus=0,status=0;  //status_ = month status = days  //(for both do while)
    do{
        cout << "Enter your departure date: "<<endl;
        cout << "Choose month (1-12): ";
        cin >> departMonth;


        if( departMonth >= 1 && departMonth <= 12)
        {
            do{
                cout << "Choose date: ";
                cin >> departDate;

                if( departDate <= monthDays[departMonth - 1] && departDate > 0 ) //array start from 0, need to -1 in order to call correctly order of the array
                {
                    status = 0; // to stop loop of do while loop (days)
                }
                else
                {
                    cout << "Invalid input\n";
                    status = 1;
                }
            }while ( status == 1 );
            monthStatus=0; // to stop do while loop (month)
        }
        else if ( departMonth == 0 || departMonth > 12) //to avoid dump error, need to put condition to tell c++ to understand this particualr input
        {
           cout << "Invalid input";
           monthStatus=1;
        }
        cout<<"\n\n";
    }while( monthStatus == 1 );

    cout << "Departure date: "<< departDate << "/" << monthName[departMonth - 1]<<"/2019";

    cout<<"\n\n------------RETURN DATE------------\n\n";
    do{
            cout << "Enter your returning date: "<<endl;
            cout << "Choose month (1-12): ";
            cin >> returnMonth;

            if(returnMonth < departMonth){
                cout<<"Invalid input. Departure date cannot be later than Returning date. Please try again"<<endl;
                cin>>returnMonth;
            }
            else {
            if(  returnMonth >= 1 && returnMonth <= 12 )
            {
                do{
                    cout << "Choose date: ";
                    cin >> returnDate;

                    if((returnDate < departDate) && (departMonth == returnMonth)){
                        cout<<"Invalid input. Departure date cannot be later than Returning date. Please try again"<<endl;
                        cin>>returnDate;
                      }else{

                        if(returnDate <= monthDays[returnMonth - 1] && returnDate > 0) //array start from 0, need to -1 in order to call correctly order of the array
                        {
                            status=0; // to stop loop of do while loop (days)
                        }
                        else
                        {
                            cout << "Invalid input\n";
                            status=1;
                        }
                    }
                }while (status == 1);
                monthStatus = 0; // to stop do while loop (month)
            }
            else if ( returnMonth == 0 || returnMonth > 12 ) //to avoid dump error, need to put condition to tell c++ to understand this particular input
            {
               cout << "Invalid input";
               monthStatus = 1;
            }
            cout<<"\n\n";
            }
            }while(monthStatus == 1);

        cout << "Return date: " << returnDate << "/" << monthName[returnMonth - 1]<<"/2019";

}


///////////////////////////////////////
void enterClassAndTicket()
{
    cout << "\nPlease enter your class type ( 1 for Business , 2 for Economy )" << endl;
    cin >> classType;
    while (classType != 1 && classType != 2)//Error check for classType
    {
            cout << "Invalid input, choices are 1 for business , 2 for economy. Please try again. "<<endl;
            cin>> classType;
    }
    cout << "\nPlease enter the number of tickets you would like to reserve" << endl;
    cin >> amountTicket;
}

void checkBanList(int noIC) // Check if passenger is banned or not
{
    std::vector<int> v;
    string line;
    passengerBanned = false;
    ifstream bannedPass;
    bannedPass.open("banlist.txt");
    if (!bannedPass.is_open())
    {
        cout << "Error while opening the file";
    }
    else
    {
        while(std::getline(bannedPass, line))
        {
            std::istringstream iss(line);
            int n;


            while (iss >> n)
            {
            v.push_back(n);
            }

        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == noIC)
            {
                cout<< "Unable to reserve tickets. You have been banned by the system for bad conducts" << endl;
                cout<< "Returning to main menu...\n";
                system("pause");
                system("cls");
                passengerBanned = true;
            }
        }
        bannedPass.close();
    }
}

void scheduleMelakaToThai(){ //Display schedule from Melaka to Thailand
    cout << "\nMelaka -> Thai" << endl;
    cout << "1) 8:00 am to 1:00 pm" << endl;
    cout << "2) 12:00 pm to 5:00 pm" << endl;
    cout << "3) 4:00 pm to 9:00 pm" << endl;
    cout << "4) 8:00 pm to 1:00 am" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleThaiToMelaka(){ //Display schedule from Thailand to Melaka
    cout << "\nThai -> Melaka" << endl;
    cout << "1)8:00 am to 1:00 pm" << endl;
    cout << "2) 12:00 pm to 5:00 pm" << endl;
    cout << "3) 4:00 pm to 9:00 pm" << endl;
    cout << "4) 8:00 pm to 1:00 am" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleMelakaToSg(){ //Display schedule from Melaka to Singapore
    cout << "\nMelaka -> Singapore" << endl;
    cout << "1) 9:00 am to 11:00 am" << endl;
    cout << "2) 11:00 am to 1:00 pm" << endl;
    cout << "3) 3:00 pm to 5:00 pm" << endl;
    cout << "4) 5:00 pm to 7:00 pm" << endl;
    cout << "5) 7:00 pm to 9:00 pm" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleSgToMelaka(){ //Display schedule from Singapore to Melaka
    cout << "\nSingapore -> Melaka" << endl;
    cout << "1) 9:00 am to 11:00 am" << endl;
    cout << "2) 11:00 am to 1:00 pm" << endl;
    cout << "3) 3:00 pm to 5:00 pm" << endl;
    cout << "4) 5:00 pm to 7:00 pm" << endl;
    cout << "5) 7:00 pm to 9:00 pm" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleSgToThai(){ //Display schedule from Singapore to Thailand
    cout << "\nSingapore -> Thai" << endl;
    cout << "1) 6:30 am to 2:30 pm" << endl;
    cout << "2) 12:30 pm to 10:00 pm" << endl;
    cout << "3) 7:30 pm to 3:00 am" << endl;
    cout << "Please select the schedule" << endl;
}

void scheduleThaiToSg(){ //Display schedule from Thailand to Singapore
    cout << "\nThai -> Singapore" << endl;
    cout << "1) 6:30 am to 2:30 pm" << endl;
    cout << "2) 12:30 pm to 10:00 pm" << endl;
    cout << "3) 7:30 pm to 3:00 am" << endl;
    cout << "Please select the schedule" << endl;
}

void getMealMenu(){
    cout<<"\nSelect the available meals:"<<endl;
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
    cout<<"\nSelect the available drinks:"<<endl;
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
    cout<< "\nDeparture\tDestination\t\tClass Type\t\tPrice" << endl;
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

    cout << "\nTrain tickets available from: \n";
    cout << "1. Melaka\n";
    cout << "2. Singapore\n";
    cout << "3. Thailand\n";

}


void getTrainDestination(){

    cout << "\nTrain tickets available to: \n";
    cout << "1. Melaka\n";
    cout << "2. Singapore\n";
    cout << "3. Thailand\n";

}


void banPassenger(int noIC) // Ban passenger by adding their IC to the ban list array
{
    ofstream outFile("banlist.txt", ios::app);
    outFile  << noIC << endl;
}

struct node
  {
    int containerNo;
    int availableSeats;
    string passengerInside[50];
    node *next;
  };

class Train
{
private:

public:
    node *head, *tail, *curr;
    int containerCreated;

    Train()
    {
        head=NULL;
        tail=NULL;
        curr=NULL;
        containerCreated = 0;
        for(int i= 0; i < 6; i++)
        {
            containerCreated++;
            node *temp=new node;
            temp->containerNo=containerCreated;
            temp->availableSeats=50;
            temp->next=NULL;
            if(head==NULL)
            {
                head=temp;
                tail=temp;
                temp=NULL;
            }
            else
            {
                tail->next=temp;
                tail=temp;
            }
        }
    }

    void addPassenger(string name)
    {
        passengerAdded = false;
        if(classType == 1) //Class type is Business
        {
            curr = head;
        }
        else //Class type is Economy
        {
            curr = head->next->next->next; //select 4th container
        }

        for(int i=0; i<2; i++) //Traverse through container 1-3 or container 3-6 depending on classType
        {
            if(amountTicket <= curr->availableSeats) // Available reservation in container
            {
                curr->passengerInside[50-curr->availableSeats] = name;
                curr->availableSeats--;
                passengerAdded = true;
                cout << "Seat successfully reserved for " << name << endl;
                break;
            }
            else //Not enough seats available in current container, go to next container
                curr = curr->next;
        }
        if(passengerAdded == false)// Passenger not added
        {
            cout << "Not enough seats available !\n";
        }
    }

    void checkSeats(int classVal)
    {
        seatsAvailable = false;
        if(classVal == 1) //Class type is Business
        {
            curr = head;
        }
        else if(classVal == 2)//Class type is Economy
        {
            curr = head->next->next->next; //select 4th container
        }

        for(int i=0; i<2; i++) //Traverse through container 1-3 or container 3-6 depending on classType
        {
            if(amountTicket <= curr->availableSeats) // Available reservation in container
            {
                seatsAvailable = true;
                cout << "The current available seats are " << curr->availableSeats << " which is enough for you\n";
                break;
            }
            else //Not enough seats available in current container, go to next container
                curr = curr->next;
        }
        if(seatsAvailable == false)// Seats not available
        {
            cout << "Not enough seats available !\n";
        }
    }

    int getBookingInfo(string name) //Get passenger booking info
    {
        passengerFound = false;
        curr = head;
        for(int i=0; (i<5) && (!passengerFound); i++)
        {
            for(int j=0 ; (j<50) && (!passengerFound); j++)
            {
                if(curr->passengerInside[j] == name)//Passenger with that name not found
                {
                    passengerFound = true;
                    return curr->containerNo;
                }
            }
            curr = curr->next;  // Go to next container
        }
    }
};

struct node2
  {
    string name;
    string phoneNum;
    int passengerIC;
    string trainName;
    string travelPoint;
    string travelTime;
    int departD, departM;
    int returnD, returnM;
    int assignedContainer;
    int passengerID;
    node2 *next;
  };


class Passenger {
private:
    int passengerCount, newContainerNo;
    string train;
public:
    node2 *head, *tail, *curr;

    Passenger()
    {
        head=NULL;
        tail=NULL;
        curr=NULL;
        passengerCount = 0;
    }

    void sortPassengerList()
    {
        node2 *temp;
        temp = head;
        int i=0;
        while(temp!=NULL)
        {
            arr[i] = temp->passengerIC;
            temp = temp->next;
            i++;
        }
        if(head == NULL)
        {
            cout << "Error\n";
        }
        else
        {
                radixsort(arr, i);
                temp = head;
                cout << "\nIC\t\t ID \tName \t\t\t Phone No \n";
                for(int j=0; arr[j] != 0 && temp != NULL; j++)
                {
                    while( temp != NULL) //Traverse the system until passenger is found OR until the end of the list
                    {

                        if(temp->passengerIC != arr[j])
                        {
                            temp = temp->next;
                        }
                        else
                        {
                            cout << temp->passengerIC << "\t\t " << temp->passengerID << " \t" << temp->name << "\t\t " <<temp->phoneNum <<"\n";
                            temp = temp->next;
                        }
                    }
                    temp = head;
                }
                cout << "\nName list sorted with IC in ascending order\n";
        }

    }

    void searchPassenger(int IC)
    {
        passengerFound = false;
        node2 *temp;
        temp = head;
        while( temp != NULL && passengerFound == false) //Traverse the system until passenger is found OR until the end of the list
        {
            if(temp->passengerIC != IC)
                temp = temp->next;
            else
            {
                cout << "\nDeparture Date   Return Date \t Container No \t Train Name \t Travel Point \t\t Travel Time\n";
                cout << temp->departD << "/" << monthName[temp->departM - 1]<<"/2019" << "   " << temp->returnD << "/" << monthName[temp->returnM - 1]<<"/2019" << "\t "<< temp->assignedContainer << "\t\t " << temp->trainName <<"\t\t "<< temp->travelPoint << "\t " << temp->travelTime <<endl;
                passengerFound = true;
            }
        }
        if ( temp == NULL) //No passenger with matching ID found in linked list after reach the end
        {
            cout << "Error! No passenger with the IC is found. \n";
            cout << "Returning to main menu\n";
        }
    }

    void displayPassengerList()
    {
        emptyList = true;
        curr = head;
        if(curr!=NULL)
        {
            cout << "ID \t Phone Number \t\t\t Passenger IC \t\t Container No \t Train Name \t Travel Point\n";
            emptyList = false;
            do
            {
                cout << curr->passengerID << "\t " << curr->phoneNum << " \t\t\t " << curr->passengerIC << "\t\t\t " << curr->assignedContainer << "\t\t " <<curr->trainName <<"\t\t "<< curr->travelPoint <<endl;
                curr = curr->next;
            }while(curr!=NULL);
        }
        else
        {
            cout << "Passenger list is empty. Returning to main menu\n";
            system("pause");
            system("cls");
        }
    }

    bool registerPassenger(string newPassName, string newPhoneNum, int newPassIC, int newContainerNo, string train, string travel, int departDate, int departMonth, int returnDate, int returnMonth, string time)//Add to the beginning
    {
        node2 *newNodePtr = new node2();
        newNodePtr->name = newPassName;
        newNodePtr->phoneNum = newPhoneNum;
        newNodePtr->passengerIC = newPassIC;
        newNodePtr->assignedContainer = newContainerNo;
        newNodePtr->trainName = train;
        newNodePtr->travelPoint = travel;
        newNodePtr->departD = departDate;
        newNodePtr->departM = departMonth;
        newNodePtr->returnD = returnDate;
        newNodePtr->returnM = returnMonth;
        newNodePtr->travelTime = time;

        newNodePtr->next = NULL;
        cout << "Passenger " << newNodePtr->name << " successfully registered!\n";
        passengerCount++;
        newNodePtr->passengerID = passengerCount;
        if(head == NULL)
        {
            head = newNodePtr;
            tail = newNodePtr;
            newNodePtr = NULL;
        }
        else
        {
            tail->next = newNodePtr;
            tail = newNodePtr;
        }
        displayPassengerList();

        return true;
    }

    bool deletePassenger(int passengerNo) //Delete passenger(remove node) from linked list using passengerNo
    {
        node2 *temp, *previous;
        temp = head;
        if(temp != NULL)
        {
            if(temp->passengerID == passengerNo)  //Delete the first node
            {
                head = head->next; // Assign the pointer connected to head as the head pointer
                temp->next = NULL; // Disconnect the old head pointer from the linked list
                delete temp; // Delete the front node
                cout << "Passenger successfully delete!\n";
                return true;
            }
            else //Delete the nodes after the first
            {
                while(temp != NULL) //Traverse the system until passenger is found OR until the end of the list
                {
                    if(temp->passengerID != passengerNo)
                    {
                        previous = temp;
                        temp = temp->next;
                    }
                    else
                    {
                        if(temp->next == NULL)
                        {
                            previous->next = NULL;
                            delete temp;
                            cout << "Passenger successfully deleted!\n";
                            return true;
                        }
                        else
                        {
                            previous->next = temp->next; //Link the node before temp(previous) to the node after temp(temp->next)
                            temp->next = NULL; //Unlink the node, that you want to delete, from linked list
                            delete temp; // Delete node
                            cout << "Passenger successfully deleted!\n";
                            return true;
                        }

                    }

                }
                if(temp != NULL)
                {
                    if(temp->passengerID == passengerNo)
                    {
                        previous->next = temp->next; //Link the node before temp(previous) to the node after temp(temp->next)
                        temp->next = NULL; //Unlink the node, that you want to delete, from linked list
                        delete temp; // Delete node
                        cout << "Passenger successfully delete!\n";
                        return true;
                    }
                }
                else//No passenger with matching ID found in linked list after reach the end
                {
                    cout << "No passenger with matching ID found\n";
                    return false;
                }
            }
        }
        else//No passenger with matching ID found in linked list after reach the end
        {
            cout << "No passenger with matching ID found\n";
            return false;
        }
    }


    void editPassenger(int passengerNo, string newPassName, string newPhoneNum, int newPassIC)
    {
        passengerFound = false;
        node2 *temp;
        temp = head;
        while( temp != NULL && passengerFound == false) //Traverse the system until passenger is found OR until the end of the list
        {
            if(temp->passengerID != passengerNo)
                temp = temp->next;
            else
            {
                temp->name = newPassName;
                temp->phoneNum = newPhoneNum;
                temp->passengerIC = newPassIC;

                cout << "Passenger (ID : " << temp->passengerID << ")'s information successfully edited!" << endl;
                passengerFound = true;
            }
        }
        if ( temp == NULL)
        {
            cout << "Error! No passenger with the ID is found. \n";
            cout << "Returning to main menu\n";
        }
    }
};

Train ML01, ML02, ML03, ML04, ML05, ML06;
Passenger P;

void menu2()
{
    string choice;
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                            Please choose one action:               		          |@@\n";
    cout<<"\t\t\t\t\t@@|                             1.Reserve ticket        		                  |@@\n";
    cout<<"\t\t\t\t\t@@|                             2.Sort passenger name list                                |@@\n";
    cout<<"\t\t\t\t\t@@|                             3.Edit passenger information                              |@@\n";
    cout<<"\t\t\t\t\t@@|                             4.Ban passenger                                           |@@\n";
    cout<<"\t\t\t\t\t@@|                             5.Delete passenger information                            |@@\n";
    cout<<"\t\t\t\t\t@@|                             6.Search and display passenger information                |@@\n";
    cout<<"\t\t\t\t\t@@|                             7.Exit                                                    |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";

    cout << "\nEnter choice: " << endl;
    cin>>choice;
    cin.ignore();

    system("cls");

    if (choice == "1") //Reserve ticket
    {
        getTrainDeparture(); // Departure list choice
        cout<< "Please choose your departure point(From Point)" << endl;
        cin>> departChoice; // Choose departure point

        while (departChoice != 1 && departChoice != 2 && departChoice != 3)//Error check for departChoice
        {
        cout << "Invalid input, choices are 1,2,3. Please try again. ";
        cin>> departChoice;
        }

        getTrainDestination();
        cout<< "Please choose your destination point(To Point)" << endl;
        cin>> destinationChoice; //Choose destination point

        while (destinationChoice != 1 && destinationChoice != 2 && destinationChoice != 3) //Error check for destinationChoice
        {
            cout << "Invalid input, choices are 1,2,3. Please try again. \n";
            cin>> destinationChoice;
        }

        if(departChoice == 1)//depart from Melaka
        {

            if(destinationChoice == departChoice)//Error
            {
                cout << "Error! Your departure point cannot be your destination point. Please try again." << endl;
                system("pause");
                system("cls");
                menu2(); //Start from beginning
            }
            getBookingList();
            if(destinationChoice == 2)//from Melaka to Singapore
            {
                enterClassAndTicket();
                ML01.checkSeats(classType);
                if(seatsAvailable == false)
                    menu2();

                if(classType == 1)
                    ticketPrice = 45 * amountTicket;
                else if(classType == 2)
                    ticketPrice = 25 * amountTicket;

                scheduleMelakaToSg();
                cin >> scheduleChoice ;
                switch (scheduleChoice)
                {
                case 1:
                    scheduleTime = "9:00 am to 11:00 am";
                    break;
                case 2:
                    scheduleTime = "11:00 am to 1:00 pm";
                    break;
                case 3:
                    scheduleTime = "3:00 pm to 5:00 pm";
                    break;
                case 4:
                    scheduleTime = "5:00 pm to 7:00 pm";
                    break;
                case 5:
                    scheduleTime = "7:00 pm to 9:00 pm";
                    break;
                default:
                    cout << "Error! Schedule choice not found. Returning to main menu\n";
                    system("pause");
                    system("cls");
                    menu2();
                    break;
                }
                assignedTrain = 1;
                printCalendar();
                cout<<""<<endl;
                system("\npause");
                system("cls");
            }
            else if(destinationChoice == 3)//from Melaka to Thai
            {
                enterClassAndTicket();
                ML02.checkSeats(classType);
                if(seatsAvailable == false)
                    menu2();
                if(classType == 1)
                    ticketPrice = 65 * amountTicket;
                else if(classType == 2)
                    ticketPrice = 35 * amountTicket;

                scheduleMelakaToThai();
                cin >> scheduleChoice ;
                switch (scheduleChoice)
                {
                case 1:
                    scheduleTime = "8:00 am to 1:00 pm";
                    break;
                case 2:
                    scheduleTime = "8:00 am to 1:00 pm";
                    break;
                case 3:
                    scheduleTime = "4:00 pm to 9:00 pm";
                    break;
                case 4:
                    scheduleTime = "8:00 pm to 1:00 am";
                    break;
                default:
                    cout << "Error! Schedule choice not found. Returning to main menu\n";
                    system("cls");
                    menu2();
                    break;
                }
                assignedTrain = 2;
                printCalendar();
                cout<<""<<endl;
                system("\npause");
                system("cls");
            }

        }
        else if(departChoice == 2)//depart from Singapore
        {

            if(destinationChoice == departChoice)//Error
            {
                cout << "Error! Your departure point cannot be your destination point. Please try again." << endl;
                menu2(); //Start from beginning
            }
            getBookingList();
            if(destinationChoice == 1)//from Singapore to Melaka
            {
                enterClassAndTicket();
                ML03.checkSeats(classType);
                if(seatsAvailable == false)
                    menu2();
                if(classType == 1)
                    ticketPrice = 45 * amountTicket;
                else if(classType == 2)
                    ticketPrice = 25 * amountTicket;

                scheduleSgToMelaka();
                cin >> scheduleChoice ;
                switch (scheduleChoice)
                {
                case 1:
                    scheduleTime = "9:00 am to 11:00 am";
                    break;
                case 2:
                    scheduleTime = "11:00 am to 1:00 pm";
                    break;
                case 3:
                    scheduleTime = "3:00 pm to 5:00 pm";
                    break;
                case 4:
                    scheduleTime = "5:00 pm to 7:00 pm";
                    break;
                case 5:
                    scheduleTime = "7:00 pm to 9:00 pm";
                    break;
                default:
                    cout << "Error! Schedule choice not found. Returning to main menu\n";
                    system("pause");
                    system("cls");
                    menu2();
                    break;
                }

                assignedTrain = 3;
                printCalendar();
                cout<<""<<endl;
                system("\npause");
                system("cls");
            }
            else if(destinationChoice == 3)//from Singapore to Thailand
            {
                enterClassAndTicket();
                ML04.checkSeats(classType);
                if(seatsAvailable == false)
                    menu2();
                if(classType == 1)
                    ticketPrice = 85 * amountTicket;
                else if(classType == 2)
                    ticketPrice = 55 * amountTicket;

                scheduleSgToThai();
                cin >> scheduleChoice ;
                switch (scheduleChoice)
                {
                case 1:
                    scheduleTime = "6:30 am to 2:30 pm";
                    break;
                case 2:
                    scheduleTime = "12:30 pm to 10:00 pm";
                    break;
                case 3:
                    scheduleTime = "7:30 pm to 3:00 am";
                    break;
                default:
                    cout << "Error! Schedule choice not found. Returning to main menu\n";
                    system("pause");
                    system("cls");
                    menu2();
                    break;
                }
                assignedTrain = 4;
                printCalendar();
                cout<<""<<endl;
                system("\npause");
                system("cls");
            }

        }
        else if(departChoice == 3)//depart from Thai
        {

            if(destinationChoice == departChoice)//Error
            {
                cout << "Error! Your departure point cannot be your destination point. Please try again." << endl;
                menu2(); //Start from beginning
            }
            getBookingList();
            if(destinationChoice == 1)//from Thai to Melaka
            {
                enterClassAndTicket();
                ML05.checkSeats(classType);
                if(seatsAvailable == false)
                    menu2();
                if(classType == 1)
                    ticketPrice = 65 * amountTicket;
                else if(classType == 2)
                    ticketPrice = 35 * amountTicket;

                scheduleThaiToMelaka();
                cin >> scheduleChoice;
                switch (scheduleChoice)
                switch (scheduleChoice)
                {
                case 1:
                    scheduleTime = "8:00 am to 1:00 pm";
                    break;
                case 2:
                    scheduleTime = "8:00 am to 1:00 pm";
                    break;
                case 3:
                    scheduleTime = "4:00 pm to 9:00 pm";
                    break;
                case 4:
                    scheduleTime = "8:00 pm to 1:00 am";
                    break;
                default:
                    cout << "Error! Schedule choice not found. Returning to main menu\n";
                    system("pause");
                    system("cls");
                    menu2();
                    break;
                }
                assignedTrain = 5;
                printCalendar();
                cout<<""<<endl;
                system("\npause");
                system("cls");
            }
            else if(destinationChoice == 2)//from Thai to Singapore
            {
                enterClassAndTicket();
                ML06.checkSeats(classType);
                if(seatsAvailable == false)
                    menu2();
                if(classType == 1)
                    ticketPrice = 85 * amountTicket;
                else if(classType == 2)
                    ticketPrice = 55 * amountTicket;

                scheduleThaiToSg();
                cin >> scheduleChoice ;
                switch (scheduleChoice)
                {
                case 1:
                    scheduleTime = "6:30 am to 2:30 pm";
                    break;
                case 2:
                    scheduleTime = "12:30 pm to 10:00 pm";
                    break;
                case 3:
                    scheduleTime = "7:30 pm to 3:00 am";
                    break;
                default:
                    cout << "Error! Schedule choice not found. Returning to main menu\n";
                    system("pause");
                    system("cls");
                    menu2();
                    break;
                }
                assignedTrain = 6;
                printCalendar();
                cout<<""<<endl;
                system("pause");
                system("cls");
            }
        }

        cout << "Would you like to order meals or drinks ? (Y or N)" << endl;
        cin >> orderChoice;
        orderChoice = toupper(orderChoice);
        while (orderChoice != 'Y' && orderChoice !=  'N') //Error check for destinationChoice
        {
                cout << "Invalid input, choices are Y or N. Please try again.\n";
                cin>> orderChoice;
                orderChoice = toupper(orderChoice);
        }
        switch (orderChoice)
        {
        case 'Y' :
            getMealMenu();
            cout << "Please enter the number of the meal that you would like to order (Type '0' to exit)" << endl;
            do
            {
                mealSelect();
            }while(mealChoice!=0);

            getDrinkMenu();
            cout << "Please enter the number of the drink that you would like to order (Type '0' to exit)" << endl;
            do
            {
                drinkSelect();
            }while(drinkChoice!=0);

            cout << "Your food and drink total is: RM " << orderTotal << endl;
            break;

        case 'N' :
            orderTotal = 0;
            break;

        default :
            cout << "Invalid choice, please enter again" << endl;
            break;
        }

        orderTotal += ticketPrice;
        cout << "The total amount you have to pay is RM " << orderTotal << endl;

        for(int i=0; i < amountTicket; i++)
        {
            cout<< "\nPlease enter your name : " << endl;
            cin >> name;
            cin.ignore();


            cout<< "Please enter your phone number" << endl;
            cin >> phoneNum;
            cin.ignore();

            cout<< "Please enter your IC number" << endl;
            cin >> passengerIC;
            cin.ignore();

            checkBanList(passengerIC);// Check if passenger is banned or not
            if(passengerBanned == true)
                menu2();
            if(assignedTrain == 1)
            {
                ML01.addPassenger(name);
                containerNo = ML01.getBookingInfo(name);
                P.registerPassenger(name, phoneNum, passengerIC, containerNo, "ML01", "Melaka to Singapore", departDate, departMonth, returnDate, returnMonth, scheduleTime);
            }
            else if(assignedTrain == 2)
            {
                ML02.addPassenger(name);
                containerNo = ML02.getBookingInfo(name);
                P.registerPassenger(name, phoneNum, passengerIC, containerNo, "ML02", "Melaka to Thai", departDate, departMonth, returnDate, returnMonth, scheduleTime);
            }

            else if(assignedTrain == 3)
            {
                ML03.addPassenger(name);
                containerNo = ML03.getBookingInfo(name);
                P.registerPassenger(name, phoneNum, passengerIC, containerNo, "ML03", "Singapore to Melaka", departDate, departMonth, returnDate, returnMonth, scheduleTime);
            }

            else if(assignedTrain == 4)
            {
                ML04.addPassenger(name);
                containerNo = ML04.getBookingInfo(name);
                P.registerPassenger(name, phoneNum, passengerIC, containerNo, "ML04", "Singapore to Thailand", departDate, departMonth, returnDate, returnMonth, scheduleTime);
            }

            else if(assignedTrain == 5)
            {
                ML05.addPassenger(name);
                containerNo = ML05.getBookingInfo(name);
                P.registerPassenger(name, phoneNum, passengerIC, containerNo, "ML05", "Thai to Melaka", departDate, departMonth, returnDate, returnMonth, scheduleTime);
            }

            else if(assignedTrain == 6)
            {
                ML06.addPassenger(name);
                containerNo = ML06.getBookingInfo(name);
                P.registerPassenger(name, phoneNum, passengerIC, containerNo, "ML06", "Thai to Singapore", departDate, departMonth, returnDate, returnMonth, scheduleTime);
            }


        }
        system("pause");
        menu2();
    }

    else if (choice == "2") //Sort passenger name list
    {
        P.sortPassengerList();
        system("\npause");
        menu2();
    }

    else if (choice == "3") //Edit passenger information (Admin control)
    {
        login lo;
        system("cls");
        P.displayPassengerList();
        if(emptyList == true)
            menu2();
        cout << "\nPlease enter the ID of the passenger you would like to edit \n";
        cin >> passengerNo;

        cout << "\nEnter the new name for the passenger: \n"; //Edit name of passenger
        cin >> newPassName;

        cout << "\nEnter the new phone number for the passenger: \n"; //Edit phone num
        cin >> newPhoneNum;

        cout << "\nEnter the new IC number for the passenger: \n"; //Edit phone num
        cin >> newPassIC;

        P.editPassenger(passengerNo, newPassName, newPhoneNum, newPassIC);
        system("pause");
        system("cls");
        menu2();
    }

    else if (choice == "4") //Ban passenger (Admin control)
    {
        login lo;
        system("cls");
        cout << "Please enter the IC of the passenger you would like to ban\n";
        cin >> passengerIC;
        banPassenger(passengerIC);
        system("pause");
        system("cls");
        menu2();
    }

    else if (choice == "5") //Delete passenger information (Admin control)
    {
        login lo;
        system("cls");
        P.displayPassengerList();
        if(emptyList == true)
            menu2();
        cout << "\nPlease enter the ID of the passenger you would like to delete\n";
        cin >> passengerNo;
        P.deletePassenger(passengerNo);
        system("pause");
        system("cls");
        menu2();
    }

    else if (choice == "6") //Search passenger with entered IC then display booking information
    {
        cout << "Please enter the IC of the passenger you would like to search\n";
        cin >> passengerIC;
        P.searchPassenger(passengerIC);
        system("\npause");
        system("cls");
        menu2();
    }

    else if (choice == "7") //Exit program
    {
        exit(0);
    }

    else //Invalid input
    {
        cout << "Invalid input. Returning to main menu" << endl;
        system("pause");
        menu2();
    }

}



int main()
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                           Train Reservation SYSTEM                                    |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
system("pause");
system("cls");

menu2();

}


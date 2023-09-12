#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;


//this is a function i use to delay a few seconds; looks nice during runtime
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//criminal's data//
struct crime {

    char desc[1000];
    int day;
    int month;
    int year;

};
struct criminal {

    char name[50] = "0";
    int age = 0;
    float height = 0;
    int birthyear = 0;
    int birthmonth = 0;
    int birthday = 0;
    int criminalID = 0;
    string nationality = "0";
    int crimeNo = 2;
    crime* crimes = new crime[crimeNo];

};


//function to add criminal//
void addcriminal(criminal*& x, int& size, criminal y)
{
    criminal* newx = new criminal[size + 1];

    if (newx == NULL) {
        cout << "Memory allocation error for addElement!" << endl;
        exit(-1);
    }

    for (int i = 0; i < size; i++)
    {
        newx[i] = x[i];
    }
    newx[size] = y;

    if (size) delete[] x;
    size++;
    x = newx;
    return;
}

//function to delete criminal//
void deletecriminal(criminal*& x, int& size, int id)
{
    int newsize = size - 1;
    int found = 0;
    int index;

    criminal* newx = new criminal[newsize];


    for (int i = 0; i <= size; i++)
    {
        if (id == x[i].criminalID)
        {
            found = 1;
            index = i;
            break;
        }

    }

    if (found == 1)
    {
        for (int j = 0; j < index; j++)
        {
            newx[j] = x[j];
        }
        for (int k = index; k < newsize; k++)
        {
            newx[k] = x[k + 1];
        }
        cout << "Criminal deleted succesfully\n";
        system("pause");
    }
    else
    {
        cout << "No criminal with this ID\nPlease try again later\n";
        system("pause");
        return;
    }


    if (size) delete[] x;
    x = newx;
    size--;
    return;
}

//function to update criminal//
void updateCriminal(criminal*& x, int size)
{
    int criminalID;
    cout << "Enter criminal ID to update: ";
    cin >> criminalID;

    int found = 0;
    int index;

    for (int i = 0; i < size; i++)
    {
        if (criminalID == x[i].criminalID)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if (found == 1)
    {
        int choice;
        cout << "What do you want to update?" << endl;
        cout << "1. Criminal ID" << endl;
        cout << "2. Name" << endl;
        cout << "3. Age" << endl;
        cout << "4. Height" << endl;
        cout << "5. Birth date" << endl;
        cout << "6. Nationality" << endl;
        cout << "7. exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter new criminal ID: ";
            cin >> x[index].criminalID;
            break;
        case 2:
            cout << "Enter new name: ";
            cin.ignore();
            cin.getline(x[index].name, 50);
            break;
        case 3:
            cout << "Enter new age: ";
            cin >> x[index].age;
            break;
        case 4:
            cout << "Enter new height: ";
            cin >> x[index].height;
            break;
        case 5:
            cout << "Enter new birth year: ";
            cin >> x[index].birthyear;
            cout << "Enter new birth month: ";
            cin >> x[index].birthmonth;
            cout << "Enter new birth day: ";
            cin >> x[index].birthday;
            break;
        case 6:
            cout << "Enter new nationality: ";
            cin >> x[index].nationality;
            break;
        case 7:
            return;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
        cout << "Criminal updated successfully." << endl;


    }
    else
    {
        cout << "Criminal not found." << endl;
    }

}
void updatecrime(criminal*& x, int size)
{
    int crimeNum;
    int criminalID;
    int found1 = 0;
    int found2 = 0;
    int index1;
    int index2;

    cout << "Enter criminal ID: ";
    cin >> criminalID;

    for (int i = 0; i < size; i++)
    {
        if (criminalID == x[i].criminalID)
        {
            found1 = 1;
            index1 = i;
            break;
        }
    }
    if (found1 != 1)
    {
        cout << "Criminal not found." << endl;
        return;
    }

    cout << "Enter crime number: ";
    cin >> crimeNum;

    if (found1 == 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (crimeNum == x[i].crimeNo)
            {
                found2 = 1;
                index2 = i;
                break;
            }
        }
    }

    if (found1 == 1 && found2 == 1)
    {
        int choice;
        cout << "What do you want to update?" << endl;
        cout << "1. Crime description" << endl;
        cout << "2. Crime date" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {

        case 1:
            cout << "Enter new crime description: ";
            cin.getline(x[index1].crimes[index2].desc, 1000);
            break;
        case 2:
            cout << "Enter new crime day: ";
            cin >> x[index1].crimes[index2].day;
            cout << "Enter new crime month: ";
            cin >> x[index1].crimes[index2].month;
            cout << "Enter new crime year: ";
            cin >> x[index1].crimes[index1].year;
            break;
        case 3:
            return;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
        cout << "Crime updated successfully." << endl;
    }


    else if (found2 != 1)
    {
        cout << "Crime not found." << endl;
    }
}

//function to add crime//
void addcrime(criminal*& x, int& crimenumber, crime y, int index1, int size)
{
    crime* newx = new crime[crimenumber + 1];

    for (int i = 0; i < crimenumber; i++)
    {
        newx[i] = x[index1].crimes[i];
    }

    newx[crimenumber] = y;

    x[index1].crimes = newx;
    x[index1].crimeNo++;

    criminal* newCriminals = new criminal[size];

    for (int i = 0; i < size; i++)
    {

        newCriminals[i] = x[i];
    }


    delete[] x;

    x = newCriminals;


    return;


}

//function to delete crime//
void deletecrime(criminal*& x, int size)
{
    int crimeNum;
    int criminalID;
    int found1 = 0;
    int found2 = 0;
    int index1;
    int index2;

    cout << "Enter criminal ID: ";
    cin >> criminalID;

    for (int i = 0; i < size; i++)
    {
        if (criminalID == x[i].criminalID)
        {
            found1 = 1;
            index1 = i;
            break;
        }
    }
    if (found1 != 1)
    {
        cout << "Criminal not found." << endl;
        system("pause");
        return;
    }

    cout << "Enter crime number: ";
    cin >> crimeNum;

    if (found1 == 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (crimeNum == x[i].crimeNo)
            {
                found2 = 1;
                index2 = i;
                break;
            }
        }
    }

    if (found2 != 1)
    {
        cout << "Crime not found." << endl;
        system("pause");
        return;
    }


    if (found1 == 1 && found2 == 1)
    {
        int newsize = x[index1].crimeNo - 1;
        crime* newx = new crime[newsize];

        for (int j = 0; j < index2; j++)
        {
            newx[j] = x[index1].crimes[j];
        }
        for (int k = index2; k < newsize; k++)
        {
            newx[k] = x[index1].crimes[k+1];
        }
        if (size) delete[] x[index1].crimes;
        x[index1].crimes = newx;
        x[index1].crimeNo--;


        criminal* newCriminals = new criminal[size];
        for (int i = 0; i < size; i++)
        {
            newCriminals[i] = x[i];
        }


        delete[] x;

        x = newCriminals;

        cout << "Crime deleted succesfully\n";
        system("pause");
        return;

    }




}

//function to search//
void search(criminal*& x, int id, int size)
{
    system("cls");
    for (int i = 0; i <= size; i++)
    {
        if (id == x[i].criminalID)
        {
            cout << "Criminal's name: " << x[i].name << endl;
            cout << "Criminal's age: " << x[i].age << endl;
            cout << "Criminal's height: " << x[i].height << endl;
            cout << "Criminal's birthday: " << x[i].birthday << "/" << x[i].birthmonth << "/" << x[i].birthyear << endl;
            cout << "Criminal's ID: " << x[i].criminalID << endl;
            cout << "Criminal's nationality: " << x[i].nationality << endl;

            {
                for (int k = 0; k < x[i].crimeNo; k++)
                {
                    cout << endl << "You are currently seeing " << x[i].name << "'s crime nb " << k + 1 << endl << endl;
                    cout << "crime description: " << x[i].crimes[k].desc << endl;
                    cout << "crime's date: " << x[i].crimes[k].day << "/" << x[i].crimes[k].month << "/" << x[i].crimes[k].year << endl;
                }
            }
            return;
        }
    }
    system("cls");
    cout << "No criminal with this id, Please try again later\n";

}


//function to display//
void display(criminal*& x, int size)
{

    cout << "Displaying all saved records:" << endl << endl;
    cout << "********************************" << endl << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Criminal nb: " << i + 1 << endl << endl;
        cout << "Criminal's name: " << x[i].name << endl;
        cout << "Criminal's ID: " << x[i].criminalID << endl << endl;
        cout << "Crime Record :" << endl;

        for (int j = 0; j < x[i].crimeNo; j++)
        {
            cout << endl << "crime number: " << j + 1 << endl;
            cout << "Crime date: " << x[i].crimes[j].day << " / " << x[i].crimes[j].month << " / " << x[i].crimes[j].year << endl;
            cout << "Crime description: " << x[i].crimes[j].desc << endl;
        }

        cout << endl << "********************************" << endl << endl;


    }
}




//main prog//
int main()
{
    char username[30];
    char password[30];
    int todo;
    int try1 = 0;
    //declaring dynamic array//
    int size = 2;
    criminal* x = new criminal[size];

    //declaring initial values 
    {
        //criminal 1
        {
            char nameof[] = "Antonio Montana";
            char desc[] = "Got into the USA without having a permission";
            strcpy(x[0].name, nameof);
            x[0].age = 39;
            x[0].height = 5.6;
            x[0].birthday = 1;
            x[0].birthmonth = 5;
            x[0].birthyear = 1941;
            x[0].criminalID = 1;
            x[0].nationality = "Cuba";
            x[0].crimeNo = 1;
            x[0].crimes[0].day = 20;
            x[0].crimes[0].month = 5;
            x[0].crimes[0].year = 1980;
            x[0].crimes[0].desc;
            strcpy(x[0].crimes[0].desc, desc);
        }

        //criminal 2
        {
            char nameof[] = "Michael Scofield";
            strcpy(x[1].name, nameof);
            x[1].age = 31;
            x[1].height = 5.8;
            x[1].birthday = 17;
            x[1].birthmonth = 2;
            x[1].birthyear = 1981;
            x[1].criminalID = 2;
            x[1].nationality = "USA";
            x[1].crimeNo = 2;

            x[1].crimes[0].day = 27;
            x[1].crimes[0].month = 3;
            x[1].crimes[0].year = 2006;
            char desc1[] = "Possession of a weapon in a public place";
            x[1].crimes[0].desc;
            strcpy(x[1].crimes[0].desc, desc1);

            x[1].crimes[1].day = 15;
            x[1].crimes[1].month = 1;
            x[1].crimes[1].year = 2007;
            char desc2[] = "Los Angeles jewelry store robbery";
            x[1].crimes[1].desc;
            strcpy(x[1].crimes[1].desc, desc2);
        }
    }

    system("cls");

    do
    {
        system("cls");
        //username & pass inputs//
        {
            cout << "\n\n\n\n\n\n";
            cout << setw(71) << "----------------------------------\n\n";
            cout << setw(73) << "***POLICE STATION MANAGEMENT SYSTEM ***\n\n";
            cout << setw(71) << "----------------------------------\n";

            cout << "\n\n\t\t\t\t\tUsername : ";
            cin.getline(username, 25);
            cout << "\t\t\t\t\t\n\t\t\t\t\tpassword : ";
            cin.getline(password, 25);
        }

        //admin inputs//
        if (strcmp(username, "admin") == 0 && strcmp(password, "pass") == 0)
        {
            //output on the screen when user enters correct username and pass of admin
            {
                cout << "\n\n\t\t\t\tYou are accessed to the system as an admin!\n\n";
                delay(1500);
                cout << "\t\t\t\t";
                system("cls");
            }



            //functions add delete edit display //
            {

                cout << "what do you want to do today admin?\n1-Add a new criminal\n2-Delete an existing criminal\n3-Add a crime\n4-Delete a crime\n5-Display all the criminals and their crimes\n6-Update date\n7-Search for a criminal\n8-Exit programme\n\n\nPlease enter the number you want\n";
                cin >> todo;

                //check for invalid input by user; out of range number//
                while (todo < 1 || todo>8)
                {
                    cout << "invalid input!\n please enter a number between 1 and 6\n";
                    cin >> todo;
                }

                // 6 cases in case the user enters a valid nb//
                while (todo >= 1 || todo <= 8)
                {
                    system("cls");
                    switch (todo)
                    {
                    case(1): //add criminal case
                    {
                        criminal y;
                        {
                            cout << "You are currently entering the new criminal's" << " data\n\n";
                            cout << "please enter the criminal's name \n";
                            cin.ignore();
                            cin.getline(y.name, 50);
                            cout << "please enter the criminal's age \n";
                            cin >> y.age;
                            cout << "please enter the criminal's height \n";
                            cin >> y.height;
                            cout << "please enter the criminal's birthyear \n";
                            cin >> y.birthyear;
                            cout << "please enter the criminal's birthmonth \n";
                            cin >> y.birthmonth;
                            cout << "please enter the criminal's birthday \n";
                            cin >> y.birthday;
                            cout << "please enter the criminal's nationality \n";
                            cin >> y.nationality;
                            {
                                cout << "please enter the criminal's ID \n";
                                cin >> y.criminalID;
                                {

                                    {
                                        for (int j = 0; j < size; j++)
                                        {
                                            while (y.criminalID == x[j].criminalID)
                                            {
                                                j = 0;
                                                cout << "already existing ID\nEnter another one\n";
                                                cin >> y.criminalID;
                                            }


                                        }
                                    }
                                }
                            }
                            cout << "please enter number of crimes \n";
                            cin >> y.crimeNo;
                            for (int k = 0; k < y.crimeNo; k++)
                            {
                                cout << "you are now entering crime nb " << k + 1 << "\n";
                                cout << "please enter the crime's year \n";
                                cin >> y.crimes[k].year;
                                cout << "please enter the crime's month \n";
                                cin >> y.crimes[k].month;
                                cout << "please enter the crime's day \n";
                                cin >> y.crimes[k].day;
                                cin.ignore();
                                cout << "please enter the crime's description (what happend) \n";
                                cin.getline(y.crimes[k].desc, 1000);
                            }


                            system("cls");
                        }
                        addcriminal(x, size, y);
                        system("cls");
                        cout << "what do you want to do today admin?\n1-Add a new criminal\n2-Delete an existing criminal\n3-Add a crime\n4-Delete a crime\n5-Display all the criminals and their crimes\n6-Update date\n7-Search for a criminal\n8-Exit programme\n\n\nPlease enter the number you want\n";
                        cin >> todo;
                        break;
                    }
                    case(2): //delete criminal case
                    {
                        int id;
                        cout << "Enter the criminal ID of the criminal you want to delete \n";
                        cin >> id;
                        deletecriminal(x, size, id);
                        system("cls");
                        cout << "what do you want to do today admin?\n1-Add a new criminal\n2-Delete an existing criminal\n3-Add a crime\n4-Delete a crime\n5-Display all the criminals and their crimes\n6-Update date\n7-Search for a criminal\n8-Exit programme\n\n\nPlease enter the number you want\n";
                        cin >> todo;
                        break;

                    }
                    case(3)://add a crime case
                    {
                        int criminalID;
                        cout << "Enter criminal ID\n";
                        cin >> criminalID;
                        int found1 = 0;
                        int index1 = 0;

                        for (int i = 0; i < size; i++)
                        {
                            if (criminalID == x[i].criminalID)
                            {
                                found1 = 1;
                                index1 = i;
                                break;
                            }
                        }

                        if (found1 == 1)
                        {
                            system("cls");
                            cout << "Criminal found\n";
                            crime y;
                            {
                                cout << "please enter the crime's year \n";
                                cin >> y.year;
                                cout << "please enter the crime's month \n";
                                cin >> y.month;
                                cout << "please enter the crime's day \n";
                                cin >> y.day;
                                cin.ignore();
                                cout << "please enter the crime's description (what happend) \n";
                                cin.getline(y.desc, 1000);
                            }

                            addcrime(x, x[index1].crimeNo, y, index1, size);
                            system("cls");
                            cout << "Crime added succesfully!\n";
                        }
                        else
                        {
                            cout << "No criminal with this ID\n";
                        }
                        system("pause");
                        system("cls");
                        cout << "what do you want to do today admin?\n1-Add a new criminal\n2-Delete an existing criminal\n3-Add a crime\n4-Delete a crime\n5-Display all the criminals and their crimes\n6-Update date\n7-Search for a criminal\n8-Exit programme\n\n\nPlease enter the number you want\n";
                        cin >> todo;
                        break;

                    }
                    case(4)://delete a crime case
                    {


                        deletecrime(x, size);
                        system("cls");
                        cout << "what do you want to do today admin?\n1-Add a new criminal\n2-Delete an existing criminal\n3-Add a crime\n4-Delete a crime\n5-Display all the criminals and their crimes\n6-Update date\n7-Search for a criminal\n8-Exit programme\n\n\nPlease enter the number you want\n";
                        cin >> todo;
                        break;

                    }
                    case(5): //the display case
                    {

                        display(x, size);
                        system("pause");
                        system("cls");
                        cout << "what do you want to do today admin?\n1-Add a new criminal\n2-Delete an existing criminal\n3-Add a crime\n4-Delete a crime\n5-Display all the criminals and their crimes\n6-Update date\n7-Search for a criminal\n8-Exit programme\n\n\nPlease enter the number you want\n";
                        cin >> todo;
                        break;
                    }
                    case(6): //the update case
                    {
                        int choice1;
                        cout << "do you want to update a criminal or a crime?\n1- criminal\n2- crime\n";
                        cin >> choice1;
                        system("cls");
                        switch (choice1)
                        {
                        case(1):
                            updateCriminal(x, size);
                            system("pause");
                            system("cls");
                            break;
                        case(2):
                            updatecrime(x, size);
                            system("pause");
                            system("cls");
                            break;
                        }
                        cout << "what do you want to do today admin?\n1-Add a new criminal\n2-Delete an existing criminal\n3-Add a crime\n4-Delete a crime\n5-Display all the criminals and their crimes\n6-Update date\n7-Search for a criminal\n8-Exit programme\n\n\nPlease enter the number you want\n";
                        cin >> todo;
                        break;
                    }
                    case(7): //the search case
                    {
                        int id;
                        cout << "Enter criminal's id\n";
                        cin >> id;
                        search(x, id, size);

                        system("pause");
                        system("cls");
                        cout << "what do you want to do today admin?\n1-Add a new criminal\n2-Delete an existing criminal\n3-Add a crime\n4-Delete a crime\n5-Display all the criminals and their crimes\n6-Update date\n7-Search for a criminal\n8-Exit programme\n\n\nPlease enter the number you want\n";
                        cin >> todo;
                        break;
                    }
                    case(8): // the exit case
                    {
                        cout << "\n\n\n\n\n\n";
                        cout << setw(71) << "----------------------------------\n\n";
                        cout << setw(57) << "System done by : \n\n";

                        cout << setw(65) << "1-Mohamed ElBialy 21P0068\n\n";
                        cout << setw(63) << "2-Youssef Tamer 21P0138\n\n";
                        cout << setw(63) << "3-Mohamed Salah 21P0117\n\n";
                        cout << setw(65) << "4-Mohamed Mostafa 21P0244\n\n";
                        cout << setw(59) << "5-Ali Tarek 21P0123\n\n";


                        cout << setw(71) << "----------------------------------\n";
                        exit(-1);
                    }
                    default:
                    {
                        cout << "invalid input!\n please enter a number between 1 and 6\n";
                        cin >> todo;
                    }
                    }
                }
            }
            break;

        }
        //end of admin authorities//




        //officer inputs and its scope//
        else if (strcmp(username, "officer") == 0 && strcmp(password, "pass") == 0)
        {
            cout << "\n\n\t\t\t\tYou are accessed to the system as an officer!\n\n";
            delay(1500);
            cout << "\t\t\t\t";
            system("cls");



            {
                cout << "What do you want to do today officer?\n1-display all the criminals and their crimes\n2-search for a criminal\n3-exit programme\n\n\nplease enter the number you want\n";
                cin >> todo;

                //check for invalid input by user; out of range number//
                while (todo < 1 || todo>4)
                {
                    cout << "invalid input!\nPlease enter a number between 1 and 4\n";
                    cin >> todo;
                }

                // 8 cases in case the user enters a valid nb//
                while (todo >= 1 || todo <= 4)
                {
                    system("cls");
                    switch (todo)
                    {
                    case(1)://display
                    {
                        display(x, size);
                        system("pause");
                        system("cls");
                        cout << "What do you want to do today officer?\n1-display all the criminals and their crimes\n2-search for a criminal\n3-exit programme\n\n\nplease enter the number you want\n";
                        cin >> todo;
                        break;

                    }
                    case(2)://search
                    {
                        int id;
                        cout << "Enter criminal's id\n";
                        cin >> id;
                        search(x, id, size);

                        system("pause");
                        system("cls");
                        cout << "What do you want to do today officer?\n1-display all the criminals and their crimes\n2-search for a criminal\n3-exit programme\n\n\nplease enter the number you want\n";
                        cin >> todo;
                        break;

                    }
                    case(3)://log out
                    {
                        cout << "\n\n\n\n\n\n";
                        cout << setw(71) << "----------------------------------\n\n";
                        cout << setw(57) << "System done by : \n\n";

                        cout << setw(65) << "1-Mohamed ElBialy 21P0068\n\n";
                        cout << setw(63) << "2-Youssef Tamer 21P0138\n\n";
                        cout << setw(63) << "3-Mohamed Salah 21P0117\n\n";
                        cout << setw(65) << "4-Mohamed Mostafa 21P0244\n\n";
                        cout << setw(59) << "5-Ali Tarek 21P0123\n\n";


                        cout << setw(71) << "----------------------------------\n";
                        exit(-1);

                    }

                    default://other
                    {
                        cout << "Invalid input!\nPLease enter a number between 1 and 3\n";
                        cin >> todo;
                    }
                    }
                }
            }

            break;

        }
        //end of officer authorities



        //if no matching username & pass//
        else
        {
            system("cls");
            try1++;
            if (try1 < 3) {
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tNo. of attempts remain: " << 3 - try1;
                cout << "\n\n\t\t\t\t\t    Please Try Again!\n ";
                delay(2500);
                cout << "\n\n";
                cout << "\t\t\t\t";
                /* system("pause");*/
            }
            else
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tNo permission to enter the system!\n\n";
                exit(-1);
            }
        }


    } while (try1 < 3);

    //end of programme
    delete[]x;
}

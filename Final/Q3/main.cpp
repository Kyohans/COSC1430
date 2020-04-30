#include "Phonebook.h"
int main()
{
   /*Phonebook myPhonebook(10);
   myPhonebook.readFromFile("input.txt");
   myPhonebook.print();*/

   /*Phonebook myPhonebook(3);
   myPhonebook.addContact("B", "bname1 bcity1 bemail1@email.com 777-777-7777");
   myPhonebook.addContact("P", "fname1 lname1 01/01/01 pemail1@email.com 888-888-888");
   myPhonebook.addContact("B", "bname2 bcity2 bemail2@email.com 999-999-9999");
   myPhonebook.addContact("P", "fname2 lname2 02/02/02 pemail2@email.com 111-111-111");
   myPhonebook.print();*/

   Phonebook myPhonebook(10);
   myPhonebook.readFromFile("input1.txt");
   myPhonebook.print();
   myPhonebook.deleteContact("777-777-7778");
   myPhonebook.deleteContact("111-111-1111");
   myPhonebook.print();
   return 0;
}
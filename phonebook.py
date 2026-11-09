phonebook={}
while True:
    print("1.ADD CONTACT")
    print("2.SEARCH CONTACT")
    print("3.UPDATE CONTACT")
    print("4.DELETE CONTACT")
    print("5.DISPLAY ALL CONTACTS")
    print("6.EXIT")
    choice=int(input("enter the choice"))  
    if choice==1:
        name=input("Enter name:")
        number=int(input("enter number:"))
        phonebook[name]=number
        print("CONTACT ADDED SUCCESSFULLY") 
    elif choice==2:
        name=input("Enter name:")
        if name in phonebook:
           print("phone number:",phonebook[name])
        else:
            print("CONTACT NOT FOUND")
    elif choice==3:
        name=input("Enter name:")
        if name in phonebook: 
            number=int(input("enter new phone number:"))
            phonebook[name]=number
            print("contact updated")
        else:
            print("contact not found") 
    elif choice==4:
        name=input("Enter name:")
        if name in phonebook: 
             del phonebook[name]
             print("CONTACT DELETED")
        else:
           print("contact not found") 
    elif choice==5:
            for name,number in phonebook.items():
                print(name,":",number)
             
    elif choice==6:
        print("exit")
        break
    else:
        print("Invalid choice")
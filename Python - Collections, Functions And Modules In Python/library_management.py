from datetime import datetime

PENALTY_PER_DAY = 10
rentals = []

def parse_date(date_str):
    return datetime.strptime(date_str, "%Y-%m-%d").date()

def add_rental():
    customer = input("Customer name: ")
    book = input("Book title: ")
    rent_date = parse_date(input("Rental date (YYYY-MM-DD): "))
    due_date = parse_date(input("Expected return date (YYYY-MM-DD): "))

    rental = {
        "customer": customer,
        "book": book,
        "rent_date": rent_date,
        "due_date": due_date,
        "returned": False
    }
    rentals.append(rental)
    print("Rental recorded successfully.")

def return_book():
    book = input("Book title to return: ")

    for rental in rentals:
        if rental["book"] == book and not rental["returned"]:
            return_date = parse_date(input("Actual return date (YYYY-MM-DD): "))
            rental["returned"] = True

            late_days = (return_date - rental["due_date"]).days
            late_fee = late_days * PENALTY_PER_DAY if late_days > 0 else 0

            print("\n--- Return Receipt ---")
            print("Customer:", rental["customer"])
            print("Book:", rental["book"])
            print("Due Date:", rental["due_date"])
            print("Return Date:", return_date)
            print("Late Fee: ₹", late_fee)
            print("----------------------")
            return

    print("No active rental found for this book.")

def show_rentals():
    if not rentals:
        print("No rentals found.")
        return

    for r in rentals:
        status = "Returned" if r["returned"] else "Pending"
        print(r["customer"], "|", r["book"], "|", status)

def menu():
    while True:
        print("\n1. Add Rental")
        print("2. Return Book")
        print("3. Show Rentals")
        print("4. Exit")

        choice = input("Choose option: ")

        if choice == "1":
            add_rental()
        elif choice == "2":
            return_book()
        elif choice == "3":
            show_rentals()
        elif choice == "4":
            break
        else:
            print("Invalid choice.")

menu()

#include <iostream>

struct Item {
    int itemNumber;
    float price;
    float discount;
    int quantity;
    Item* next;
};

float calculateTotalCost(Item* head) {
    float totalCost = 0.0;
    while (head != nullptr) {
        float discountedPrice = head->price - (head->price * head->discount / 100);
        float itemCost = discountedPrice * head->quantity;
        totalCost += itemCost;
        head = head->next;
    }
    return totalCost;
}

void addItem(Item*& head, int itemNumber, float price, float discount, int quantity) {
    Item* newItem = new Item;
    newItem->itemNumber = itemNumber;
    newItem->price = price;
    newItem->discount = discount;
    newItem->quantity = quantity;
    newItem->next = nullptr;

    if (head == nullptr) {
        head = newItem;
    } else {
        Item* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newItem;
    }
}

void displayItems(Item* head) {
    cout << "\n\nItem Details:\n";
    while (head != nullptr) {
        cout << "Item Number: " << head->itemNumber << "\n";
        cout << "Price: " << head->price << "\n";
        cout << "Discount: " << head->discount << "%\n";
        cout << "Quantity: " << head->quantity << "\n";
        cout << "----------------------\n";
        head = head->next;
    }
}

void deleteItems(Item*& head) {
    while (head != nullptr) {
        Item* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Item* itemList = nullptr;

    // Get user input and add items to the list
    int itemNumber, quantity;
    float price, discount;
    char addMore;
    do {
        cout << "Enter Item Number: ";
        cin >> itemNumber;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Discount (%): ";
        cin >> discount;
        cout << "Enter Quantity: ";
        cin >> quantity;

        addItem(itemList, itemNumber, price, discount, quantity);

        cout << "Do you want to add more items? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    // Display item details
    displayItems(itemList);

    // Calculate total cost after discounts
    float totalCost = calculateTotalCost(itemList);
    cout << "Total Cost after Discount: " << totalCost << std::endl;

    // Clean up memory
    deleteItems(itemList);

    return 0;
}

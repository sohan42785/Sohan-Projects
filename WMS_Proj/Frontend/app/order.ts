// This is the order interface
//id = order id
//name = item name
//import { Date } from "@angular/common";

//description = other order info (shipping address, shipping time, etc.)
export interface Order {
    //Order ID
    id: number;
    /**
     * NEED TO FIX THIS -- Need to take in an item object here
     * 
     */
    itemInfo: string;
    //Order status
    status: string;
    //Order created
    orderCreated: string;
    //Order completed
    orderCompleted: string;
}
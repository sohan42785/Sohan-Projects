// Creating this mock list of items to test the front end
import { Order } from './order';

export const ORDERS: Order[] = [
    {   
        id: 1234556, 
        itemInfo: 'item1, item2, item3',
        status: 'Pending',
        orderCreated: '09-15-2022',
        orderCompleted: '09-20-2022'
    },

    {   
        id: 126783, 
        itemInfo: 'item1, item2',
        status: 'Shipped',
        orderCreated: '01-08-1997',
        orderCompleted: '01-08-1997'
    },

    {   
        id: 687364, 
        itemInfo: 'item1',
        status: 'Shipped',
        orderCreated: '05-22-2011',
        orderCompleted: '05-26-2011'
    },

    {
        id: 321, 
        itemInfo: 'item1',
        status: 'Shipped',
        orderCreated: '09-01-2021',
        orderCompleted: '09-04-2021'
    },

    {
        id: 1234, 
        itemInfo: 'item1',
        status: 'Shipped',
        orderCreated: '05-20-2021',
        orderCompleted: '05-23-2021'
    }
];
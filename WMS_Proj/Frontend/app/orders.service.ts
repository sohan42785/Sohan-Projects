import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable, Subject } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class OrdersService {

  baseUrl = 'http://localhost:8080/api/orders';

  constructor(private http: HttpClient) {}

  getTotalOrdersShipped() {
    return this.http.get<any>(`${this.baseUrl}/shipped/count`);
  }

  getAvgTimeToShipp() {
    return this.http.get<any>(`${this.baseUrl}/shipped/avg`);
  }

  getPendingOrders(){
    return this.http.get<any>(`${this.baseUrl}/pending`)
  }

  getAllOrders(){
    return this.http.get<any>(`${this.baseUrl}/all`)
  }
  getShippedOrders(){
    return this.http.get<any>(`${this.baseUrl}/shipped`)
  }


  getTableOrders(){
    return this.http.get<any>(`${this.baseUrl}/all`);
  }
  updateOrderStatus(){
    //return this.http.put<any>(`${this.baseUrl}/update/${id}/${s}`, orders)
  }

  getTopSellingItems() {
    return this.http.get<any>(`${this.baseUrl}/top-selling`);
  }
  
  getOrders(id: number)
  {
    return this.http.get<any>(`${this.baseUrl}/${id}`);
  }
}

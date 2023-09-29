import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { Location } from '@angular/common';

import { OrdersService } from '../orders.service';
import { Order }  from '../order';

@Component({
  selector: 'app-order-detail-window',
  templateUrl: './order-detail-window.component.html',
  styleUrls: ['./order-detail-window.component.css']
})
export class OrderDetailWindowComponent implements OnInit {

  orders: any
  id:any;

  constructor(
    private route: ActivatedRoute,
    private orderService: OrdersService,
    private location: Location
  ) {this.id =this.route.snapshot.params['id'];}

  ngOnInit(): void {
    
   console.log(this.id);
   
      this.orderService.getOrders(this.id).subscribe(order =>{
        this.orders = order;
      })
    }

  getOrder(): void {
    const id = Number(this.route.snapshot.paramMap.get('id'));
    this.orderService.getOrders(id)
    .subscribe(orders => this.orders = orders);
  }

  goBack(): void {
    this.location.back();
  }

}
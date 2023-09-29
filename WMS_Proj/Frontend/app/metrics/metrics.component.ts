import { Component, OnInit } from '@angular/core';
import { OrdersService } from '../orders.service';

@Component({
  selector: 'app-metrics',
  templateUrl: './metrics.component.html',
  styleUrls: ['./metrics.component.css']
})
export class MetricsComponent implements OnInit {
  totalOrdersShipped: any;
  avgTime: any;
  topSellingItems: any;

  constructor(private _ordersService: OrdersService) { }

  ngOnInit(): void {
    this.getTotalOrdersShipped();
    this.getAvgTimeToShip();
    this.getTopSellingItems();

    setInterval(() => {
      this.getTotalOrdersShipped();
      this.getAvgTimeToShip();
      this.getTopSellingItems();
    }, 5000);
  }

  getTopSellingItems() {
    this._ordersService.getTopSellingItems().subscribe(topSellingItems => {
      this.topSellingItems = topSellingItems;
    });
  }

  getTotalOrdersShipped() {
    this._ordersService.getTotalOrdersShipped().subscribe(totalOrdersShipped => {
      this.totalOrdersShipped = totalOrdersShipped;
    })
  }

  getAvgTimeToShip() {
    this._ordersService.getAvgTimeToShipp().subscribe(avgTime => {
      this.avgTime = avgTime;
    })
  }
}

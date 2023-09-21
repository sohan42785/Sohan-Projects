//
//  detailViewController.swift
//  FinalProject
//
//  Created by SOHAN on 10/31/20.
//  Copyright © 2020 Sohan Byrapuneni. All rights reserved.
//

import UIKit
import MapKit

class detailViewController: UIViewController {

    
    @IBOutlet weak var stockLabelName: UILabel!
    
    @IBOutlet weak var map: MKMapView!
    
    @IBOutlet weak var boughtPrice: UITextView!
    
    @IBOutlet weak var currentPrice: UITextView!
    
    @IBOutlet weak var netChange: UITextView!
    
    
    
    var labelText:String = ""
    var priceText:Double = 0
    
    var locationLong:Double = 0
    var locationlat:Double = 0
    
   /* struct stockResults: Decodable{
        let globe:Double?
        
        private enum CodingKeys : String, CodingKey {
            case globe = "05. price"
        }
    }
    private enum CodingKeys : String, CodingKey {
        case stockResults = "Global Quote"
    }*/
    
    struct stockResults: Decodable{
        let limit:Int?
        let offset:Int?
        let count:Int?
        let total:Int?
        var pagination: [data]
    }
    struct data: Decodable{
        let date:String?
        let symbol:String?
        let exchange:String?
        let open:Double?
        let high:Double?
        let low:Double?
        let close:Double?
        let volume:Double?
        let adj_open:Double?
        let adj_high:Double?
        let adj_low: Double?
        let adj_close:Double?
        let adj_volume:Double?
        
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        print(locationLong)
        print(locationlat)
        
        stockLabelName.text = labelText
        boughtPrice.text = String(priceText)
        
        
        var loca:CLLocationCoordinate2D = CLLocationCoordinate2DMake(locationlat, locationLong)
        
        var region:MKCoordinateRegion = MKCoordinateRegion(center: loca, latitudinalMeters: 1000, longitudinalMeters: 1000)
        
        map.setRegion(region, animated: true)
        
        let annotation = MKPointAnnotation()
        annotation.coordinate = loca
        annotation.title = "Stock Location"
        
        map.addAnnotation(annotation)
        
        
        //alphavantage
        //let urlString = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=\(labelText)&apikey=113B3VE2Y5UYFLBV"
        
        //marketstack.com
        let urlString = "http://api.marketstack.com/v1/eod?access_key=26a78499f48605aeb736af1462704315&symbols=\(labelText)"
        
        print(urlString)
        
        let url = URL(string: urlString)
        let urlSession = URLSession.shared
        
        let jsonQuery = urlSession.dataTask(with: url!, completionHandler: { data, response, error -> Void in
        if(error != nil){
            print(error!.localizedDescription)
        }
        else{
        
        print(response)
        print(data)
        
        let decoder = JSONDecoder()
       // let jsonResult = try! decoder.decode(stockResults.self, from: data!)
            
            if let jsonResult = try? JSONSerialization.jsonObject(with: data!, options: JSONSerialization.ReadingOptions.mutableContainers) as! NSDictionary {
                let setOne = (jsonResult["data"] as? [NSDictionary])!
                print(setOne)
                
                DispatchQueue.main.async{
                    // variable* 100 variable.round(), /100
                    self.currentPrice.text = String((setOne[0]["close"] as? Double)!)
                    self.netChange.text = String((setOne[0]["close"] as? Double)! - self.priceText)
                }
            }
     //   print(jsonResult)
        
        
         /*   DispatchQueue.main.async{
                self.currentPrice.text = String(jsonResult.pagination[0].close!)
                self.netChange.text = String(self.priceText - jsonResult.pagination[0].close!)
            } */
        
        // Do any additional setup after loading the view.
            }
        }
    )
    
    jsonQuery.resume()

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */
    }
}

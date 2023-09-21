//
//  ViewController.swift
//  FinalProject
//
//  Created by SOHAN on 10/30/20.
//  Copyright © 2020 Sohan Byrapuneni. All rights reserved.
//

import UIKit
import MapKit
import Firebase
//import FirebaseFirestoreSwift

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, UIImagePickerControllerDelegate, UINavigationControllerDelegate, CLLocationManagerDelegate {
    
    @IBOutlet weak var stockTable: UITableView!
    
    var stockList: stockAccount = stockAccount()
    
    var lastStock:String = ""
    
    var longi:Double = 0.0
    var lat:Double = 0.0
    
    var manager: CLLocationManager!
    
    let picker = UIImagePickerController()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        manager = CLLocationManager()
        manager.delegate = self
        manager.desiredAccuracy = kCLLocationAccuracyBest
        manager.requestWhenInUseAuthorization()
        manager.startUpdatingLocation()
        
        stockTable.rowHeight = 95
        
      /*  let db = Firestore.firestore()
        
        var ref: DocumentReference? = nil
        ref = db.collection("users").addDocument(data: [
            "first": "Ada",
            "last": "Lovelace",
            "born": 1815
        ]) { err in
            if let err = err {
                print("Error adding document: \(err)")
            } else {
                print("Document added with ID: \(ref!.documentID)")
            }
        } */

        
        // Do any additional setup after loading the view.
    }


    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return stockList.stockAccount.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "myCell", for: indexPath) as! StockTableViewCell
         
        cell.layer.borderWidth = 1.0
        cell.stockLabel.text = stockList.stockAccount[indexPath.row].stockName!;
    
        cell.stockImage.image = UIImage(data: stockList.stockAccount[indexPath.row].stockImage!)
        
        
        return cell
        
    }
    
    func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool
    {
        return true
    }
    
    func tableView(tableView: UITableView, editingStyleForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell.EditingStyle { return UITableViewCell.EditingStyle.delete }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath)
    {
      
        stockList.stockAccount.remove(at: indexPath.row)
        
        //Method 1
        self.stockTable.beginUpdates()
        self.stockTable.deleteRows(at: [indexPath], with: .automatic)
        self.stockTable.endUpdates()
        
    }
    
    @IBAction func add(_ sender: UIBarButtonItem) {
        
        let alertController = UIAlertController(title: "Add Stock", message: "", preferredStyle: .alert)
         
         let searchAction = UIAlertAction(title: "Ok", style: .default) { (action) in
         
         let firstTextField = alertController.textFields![0] as UITextField
         let secondTextField = alertController.textFields![1] as UITextField
             
         let text = firstTextField.text!
         let text2 = secondTextField.text!
          
         
          let indexPath = IndexPath (row: self.stockList.stockAccount.count - 1, section: 0)
        /*  self.cityTable.beginUpdates()
          self.cityTable.insertRows(at: [indexPath], with: .automatic)
          self.cityTable.endUpdates() */
         
             
        // let photoPicker = UIImagePickerController ()
         self.picker.delegate = self
         self.picker.sourceType = .photoLibrary
         // display image selection view
         self.present(self.picker, animated: true, completion: nil)
             
            let f6 = stock(sn: text, sp: Double(text2)!, slat: self.lat, slong: self.longi, si: UIImage(imageLiteralResourceName: "apple copy.png").pngData()!)
             
         self.lastStock = text
         
         self.stockList.stockAccount.append(f6)
             
         self.stockTable.reloadData()
         
         }
         
         
         let cancelAction = UIAlertAction(title: "Cancel", style: .cancel) { (action) in
         }
         
         alertController.addTextField { (textField) in
             textField.placeholder = "Enter Stock Symbol"
         }
         
         alertController.addTextField { (textField) in
             textField.placeholder = "Enter Stock Price"
             textField.keyboardType = .decimalPad
         }
         
         alertController.addAction(searchAction)
         alertController.addAction(cancelAction)
         
         self.present(alertController, animated: true, completion: nil)
        
        
        
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let userLocation:CLLocation = locations[0]
        longi = userLocation.coordinate.longitude
        lat = userLocation.coordinate.latitude
    }
    
    
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]){
        
        picker .dismiss(animated: true, completion: nil)

        // fetch resultset has the recently added row without the image
        // this code ad the image to the row
        if let stock = stockList.stockAccount.last, let image = info[UIImagePickerController.InfoKey.originalImage] as? UIImage {
            stock.stockImage = image.pngData()! as Data
            //update the row with image
            self.stockTable.reloadData()
            
        }
        
    }
    
    fileprivate func convertFromUIImagePickerControllerInfoKeyDictionary(_ input: [UIImagePickerController.InfoKey: Any]) -> [String: Any] {
        return Dictionary(uniqueKeysWithValues: input.map {key, value in (key.rawValue, value)})
    }
    
    fileprivate func convertFromUIImagePickerControllerInfoKey(_ input: UIImagePickerController.InfoKey) -> String {
        return input.rawValue
    }
    
    
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        
        let selectedIndex: IndexPath = self.stockTable.indexPath(for: sender as! UITableViewCell)!
        
        let stock = stockList.stockAccount[selectedIndex.row]
        
        let des = segue.destination as!
        detailViewController
        
            des.labelText = stock.stockName!
            des.priceText = stock.stockPrice!
            des.locationlat = stock.stockLatitude!
            des.locationLong = stock.stockLongitude!
    }
    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
}


//
//  stockAccount.swift
//  FinalProject
//
//  Created by SOHAN on 10/31/20.
//  Copyright © 2020 Sohan Byrapuneni. All rights reserved.
//

import Foundation

class stockAccount{
    var stockAccount:[stock] = []
    
    init(){ }
    
}


class stock{
    var stockName:String?
    var stockPrice:Double?
    var stockLatitude:Double?
    var stockLongitude:Double?
    var stockImage:Data?
    
    init(sn:String, sp:Double, slat:Double, slong:Double, si:Data){
        stockName = sn
        stockPrice = sp
        stockLatitude = slat
        stockLongitude = slong
        stockImage = si
    }
    
}

//
//  StockTableViewCell.swift
//  FinalProject
//
//  Created by SOHAN on 11/23/20.
//  Copyright © 2020 Sohan Byrapuneni. All rights reserved.
//

import UIKit

class StockTableViewCell: UITableViewCell {

    @IBOutlet weak var stockImage: UIImageView!{
        didSet {
        stockImage.layer.cornerRadius = stockImage.bounds.width / 2
        stockImage.clipsToBounds = true
        }
    }
    
    @IBOutlet weak var stockLabel: UILabel!
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}

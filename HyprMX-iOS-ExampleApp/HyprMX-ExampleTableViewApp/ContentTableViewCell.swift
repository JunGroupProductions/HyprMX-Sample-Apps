//
//  ContentTableViewCell.swift
//  HyprMX-ExampleTableViewApp
//
//  Created by Sean Reinhardt on 7/22/21.
//  Copyright © 2021 hyprmx. All rights reserved.
//

import UIKit

class ContentTableViewCell: UITableViewCell {

    @IBOutlet weak var contentLabel: UILabel!
    
    override func prepareForReuse() {
        self.contentLabel.text = ""
    }
}

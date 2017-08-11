//
//  ViewController.swift
//  LeetCodeSwift
//
//  Created by Gemini_Mxz on 2017/8/9.
//  Copyright © 2017年 Mxz. All rights reserved.
//

import UIKit


class ViewController: UIViewController,UITableViewDataSource,UITableViewDelegate {

    let tableView = UITableView.init(frame: CGRect.init(x: 0, y: 20, width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height-20))
    
    let data = [["1.Two Sum", ""],["1.Two Sum", ""]];
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.view.addSubview(tableView);
        
        tableView.delegate = self;
        tableView.dataSource = self;
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    
        return data.count;
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell:UITableViewCell = UITableViewCell.init(style: UITableViewCellStyle.default, reuseIdentifier: nil)

        cell.textLabel?.text = data[indexPath.row][0];
        
        return cell;
    }

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        
        return 60;
    }
    
    public func tableView(_ tableView: UITableView, willSelectRowAt indexPath: IndexPath) -> IndexPath? {
    
        switch indexPath.row {
        case 0:
            NSLog("hello world %d", indexPath.row);
            
            let data = [3,2,4];
            let target = 6;
            
            //let res = TwoSum.twoSum(data, target);
            
            break;
            
        case 1:
            NSLog("hello world %d", indexPath.row);
            break;
        default:
        
            break;
        }
        
        return indexPath;
    }
}


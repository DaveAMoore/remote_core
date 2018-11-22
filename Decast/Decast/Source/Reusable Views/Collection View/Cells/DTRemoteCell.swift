//
//  DTRemoteCell.swift
//  Decast
//
//  Created by David Moore on 11/20/18.
//  Copyright © 2018 David Moore. All rights reserved.
//

import SFKit

class DTRemoteCell: UICollectionViewCell {
    
    // MARK: - Properties
    
    private var widthConstraint: NSLayoutConstraint!
    
    // MARK: - Outlets
    
    /// Label which displays the title.
    @IBOutlet var titleLabel: UILabel!
    
    // MARK: - Lifecycle
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        // Add a width constraint.
        translatesAutoresizingMaskIntoConstraints = false
        widthConstraint = widthAnchor.constraint(equalToConstant: 0)
    }
    
    override func appearanceStyleDidChange(_ previousAppearanceStyle: SFAppearanceStyle) {
        super.appearanceStyleDidChange(previousAppearanceStyle)
        
        // Update coloring.
        let colorMetrics = UIColorMetrics(forAppearance: appearance)
        contentView.backgroundColor = colorMetrics.color(forRelativeHue: .pink)

        // Configure the rounding.
        contentView.clipsToBounds = true
        contentView.layer.cornerRadius = 12.0
        
        // Configure the shadow
        backgroundColor = .clear
        clipsToBounds = false
        layer.shadowColor = colorMetrics.color(forRelativeHue: .black).cgColor
        layer.shadowRadius = 4
        layer.shadowOpacity = 0.15
        
        // Update the title label.
        titleLabel.textColor = colorMetrics.color(forRelativeHue: .white)
        titleLabel.font = UIFontMetrics.default.scaledFont(for: UIFont.systemFont(ofSize: 20, weight: .bold))
    }
    
    // MARK: - Layout
    
    /// Sets the width of the cell.
    func setWidth(to width: CGFloat) {
        widthConstraint.constant = width
        widthConstraint.isActive = true
    }
}

//
//  HyprMXBannerViewRepresentable.swift
//

import SwiftUI
import HyprMX

/**
  * A UIViewRepresentable allows a UIView to be added to your SwiftUI View
  * You will need to initialize and return a HyprMXBannerView in the makeUIView() method
  * Perform any updates to the view in updateUIView()
  *
  * This example implementation communicates with a BannerViewModel that configures the placementName, adSize, and acts as the placementDelegate
 */
struct HyprMXBannerViewRepresentable: UIViewRepresentable {
    typealias UIViewType = HyprMXBannerView
    
    @State var bannerViewModel:BannerViewModel
    
    // Keeping a reference to the bannerView will allow you to call loadAd on the object
    var bannerView:HyprMXBannerView = HyprMXBannerView.init()
    func loadButtonTapped() {
        bannerViewModel.loadAd(bannerView: bannerView)
    }
    
    func makeUIView(context: Context) -> HyprMXBannerView {
        // You can set your placementName, adSize in the initializer or by setting these properties.
        // They must be set before you load your first ad.
        bannerView.placementName = bannerViewModel.placementName
        bannerView.adSize = bannerViewModel.adSize
        bannerView.placementDelegate = bannerViewModel
        return bannerView
    }
    
    func updateUIView(_ uiView: HyprMXBannerView, context: Context) {
        uiView.adSize = bannerViewModel.adSize
    }
    
}

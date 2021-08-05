//
//  ContentView.swift
//  HyprMX-SwiftUIExampleApp
//
//  Created by Sean Reinhardt on 7/22/21.
//  Copyright © 2021 hyprmx. All rights reserved.
//

import SwiftUI
import HyprMX
import Combine
let PLACEMENT_NAME:String = "banner_320_50"
let BANNER_WIDTH:Float = 320.0
let BANNER_HEIGHT:Float = 50.0

struct ContentView: View {
    let viewModel = BannerViewModel.init(placement: BannerPlacement(placementName: PLACEMENT_NAME, adWidth: BANNER_WIDTH, adHeight: BANNER_HEIGHT)
    )
    @State var bannerView:HyprMXBannerViewRepresentable
    @State private var statusText = ""
    @State private var placementNameLabel = PLACEMENT_NAME
    @State private var loadButtonDisabled = true
    @State private var loadButtonColor = Color.gray
    
    init() {
        self.bannerView = HyprMXBannerViewRepresentable.init(bannerViewModel: viewModel)
    }
    
    var body: some View {
        VStack(alignment: .center) {
            Text("HyprMXBannerView Demo").lineLimit(nil).font(.title)
            Spacer().frame(height: 10)
            Text(placementNameLabel).lineLimit(nil).onReceive(viewModel.placementNameChanged) { text in
                if (text.count > 0) {
                    self.placementNameLabel = text
                }
            }.font(.callout)
            Spacer().frame(height: 10)
            Button(action: {
                bannerView.loadButtonTapped()
            }) {
                HStack {
                    Text("Load Ad")
                        .fontWeight(.semibold)
                        .font(.headline)
                }
                .padding()
                .foregroundColor(.white)
                .background(loadButtonColor)
                .cornerRadius(40).onReceive(viewModel.loadAdButtonEnableChanged) { enabled in
                    self.loadButtonDisabled = !enabled
                    self.loadButtonColor = enabled ? Color.green : Color.gray
                }
            }.disabled(loadButtonDisabled)
            Spacer().frame(height: 10)
            bannerView.frame(width: CGFloat(BANNER_WIDTH), height: CGFloat(BANNER_HEIGHT), alignment: .center)
            Spacer().frame(height: 10)
            Text(statusText)
                .onReceive(viewModel.statusTextChanged) { text in
                    self.statusText = text
                }
                .font(.footnote)
            Spacer().frame(height: 10)
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

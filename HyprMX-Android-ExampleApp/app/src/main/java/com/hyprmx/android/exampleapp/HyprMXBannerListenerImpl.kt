package com.hyprmx.android.exampleapp

import android.util.Log
import com.hyprmx.android.sdk.banner.HyprMXBannerListener
import com.hyprmx.android.sdk.banner.HyprMXBannerView
import com.hyprmx.android.sdk.core.HyprMXErrors

class HyprMXBannerListenerImpl : HyprMXBannerListener {

  /**
   *  Called when an ad is loaded for the given banner placement.
   */
  override fun onAdLoaded(ad: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdLoaded for ${ad.placementName}")
  }

  /**
   *  Called when there was an ad that failed to load.
   */
  override fun onAdFailedToLoad(ad: HyprMXBannerView, error: HyprMXErrors) {
    Log.d(MainActivity.TAG, "onAdFailedToLoad for ${ad.placementName}")
  }

  /**
   * Called when an user clicks on an ad for a given banner placement.
   */
  override fun onAdClicked(ad: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdClicked for ${ad.placementName}")
  }

  /**
   * Called when an user opens on an ad for a given banner placement.
   */
  override fun onAdOpened(ad: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdOpened for ${ad.placementName}")
  }

  /**
   * Called when an ad is closed. Your application should resume here.
   */
  override fun onAdClosed(ad: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdClosed for ${ad.placementName}")
  }

  /**
   * Called when an user has navigated away from the app.
   */
  override fun onAdLeftApplication(ad: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdLeftApplication for ${ad.placementName}")
  }
}

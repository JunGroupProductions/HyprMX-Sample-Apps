package com.hyprmx.android.exampleapp

import android.util.Log
import com.hyprmx.android.sdk.banner.HyprMXBannerListener
import com.hyprmx.android.sdk.banner.HyprMXBannerView

class HyprMXBannerListenerImpl : HyprMXBannerListener {
  /**
   * Called when an user clicks on an ad for a given banner placement.
   */
  override fun onAdClicked(view: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdClicked for ${view.placementName}")
  }

  /**
   * Called when an user opens on an ad for a given banner placement.
   */
  override fun onAdOpened(view: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdOpened for ${view.placementName}")
  }

  /**
   * Called when an ad is closed. Your application should resume here.
   */
  override fun onAdClosed(view: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdClosed for ${view.placementName}")
  }

  /**
   * Called when an user has navigated away from the app.
   */
  @Suppress("OVERRIDE_DEPRECATION")
  override fun onAdLeftApplication(view: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdLeftApplication for ${view.placementName}")
  }

  /**
   * Called when an ad was impressed.
   */
  override fun onAdImpression(view: HyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdImpression for ${view.placementName}")
  }
}

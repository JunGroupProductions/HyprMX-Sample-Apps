package com.hyprmx.android.exampleapp

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.hyprmx.android.exampleapp.databinding.ActivityXmlIntegrationBannerBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerListener
import com.hyprmx.android.sdk.banner.HyprMXBannerView
import com.hyprmx.android.sdk.core.HyprMXErrors

/**
 * This activity demonstrates how to integrate a banner using XML
 *
 * activity_xml_integration_banner.xml shows how to integrate using xml
 */
class BannerXMLIntegrationActivity : AppCompatActivity(), HyprMXBannerListener {

  private lateinit var binding: ActivityXmlIntegrationBannerBinding

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    binding = ActivityXmlIntegrationBannerBinding.inflate(layoutInflater)
    setContentView(binding.root)

    binding.banner1.apply {
      // If you have not set the placement name or size in xml
      // you will need to set them here before calling load ad
      //
      // placementName = BANNER_PLACEMENT_NAME
      // adSize = HyprMXBannerSize.HyprMXAdSizeBanner
      listener = this@BannerXMLIntegrationActivity

      // This must be called after HyprMX has initialized or you will not get inventory
      loadAd()
    }
  }

  override fun onDestroy() {
    super.onDestroy()
    // HyprMX recommends calling destroy on the HyprMXBannerView
    // when you are no longer using the banner or the activity is being destroyed
    binding.banner1.apply {
      listener = null
      destroy()
    }
  }

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

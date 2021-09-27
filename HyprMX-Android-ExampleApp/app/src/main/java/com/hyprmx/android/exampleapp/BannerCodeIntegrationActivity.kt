package com.hyprmx.android.exampleapp

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.constraintlayout.widget.ConstraintSet
import androidx.constraintlayout.widget.ConstraintSet.BOTTOM
import androidx.constraintlayout.widget.ConstraintSet.END
import androidx.constraintlayout.widget.ConstraintSet.START
import androidx.constraintlayout.widget.ConstraintSet.TOP
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_PLACEMENT_NAME
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_SIZE
import com.hyprmx.android.exampleapp.databinding.ActivityCodeIntegrationBannerBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerListener
import com.hyprmx.android.sdk.banner.HyprMXBannerView
import com.hyprmx.android.sdk.core.HyprMXErrors

/**
 * This activity demonstrates how to integrate a banner using code
 *
 * activity_xml_integration_banner.xml shows how to integrate using xml
 */
class BannerCodeIntegrationActivity : AppCompatActivity(), HyprMXBannerListener {

  private lateinit var binding: ActivityCodeIntegrationBannerBinding
  private var hyprMXBannerView: HyprMXBannerView? = null

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    binding = ActivityCodeIntegrationBannerBinding.inflate(layoutInflater)
    setContentView(binding.root)

    hyprMXBannerView = HyprMXBannerView(this@BannerCodeIntegrationActivity, null).apply {
      placementName = BANNER_PLACEMENT_NAME
      adSize = BANNER_SIZE
      id = R.id.hyprmx_banner_view

      // Set the size to the size of the requested banner
      val params = ConstraintLayout.LayoutParams(dpToPx(320), dpToPx(50))
      layoutParams = params

      binding.constraintLayout.addView(this)
      loadAd()
    }

    updateViewConstraints()
  }

  override fun onDestroy() {
    // HyprMX recommends calling destroy on the HyprMXBannerView
    // when you are no longer using the banner or the activity is being destroyed
    hyprMXBannerView?.destroy()
    hyprMXBannerView = null
    super.onDestroy()
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

  private fun updateViewConstraints() {
    ConstraintSet().apply {
      clone(binding.constraintLayout)
      connect(R.id.hyprmx_banner_view, START, R.id.constraint_layout, START)
      connect(R.id.hyprmx_banner_view, END, R.id.constraint_layout, END)
      connect(R.id.hyprmx_banner_view, TOP, R.id.constraint_layout, TOP)
      connect(R.id.hyprmx_banner_view, BOTTOM, R.id.constraint_layout, BOTTOM)

      // Apply the changes
      applyTo(binding.constraintLayout)
    }
  }
}

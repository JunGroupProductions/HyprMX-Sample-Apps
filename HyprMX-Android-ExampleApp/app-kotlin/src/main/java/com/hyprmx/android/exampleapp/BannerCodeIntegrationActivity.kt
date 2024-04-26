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
import androidx.lifecycle.lifecycleScope
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_PLACEMENT_NAME
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_SIZE
import com.hyprmx.android.exampleapp.common.databinding.ActivityCodeIntegrationBannerBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerListener
import com.hyprmx.android.sdk.banner.HyprMXBannerView
import kotlinx.coroutines.launch

/**
 * This activity demonstrates how to integrate a banner using code
 *
 * activity_xml_integration_banner.xml shows how to integrate using xml
 */
class BannerCodeIntegrationActivity : AppCompatActivity(), HyprMXBannerListener by HyprMXBannerListenerImpl() {

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

      lifecycleScope.launch {
        if (loadAd()) {
          Log.d(TAG, "onAdLoaded for $placementName")
        } else {
          Log.d(TAG, "onAdFailedToLoad for $placementName")
        }
      }
    }.also(binding.constraintLayout::addView)

    updateViewConstraints()
  }

  override fun onDestroy() {
    // HyprMX recommends calling destroy on the HyprMXBannerView
    // when you are no longer using the banner or the activity is being destroyed
    hyprMXBannerView?.destroy()
    hyprMXBannerView = null
    super.onDestroy()
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

  companion object {
    const val TAG = "BCIActivity"
  }
}

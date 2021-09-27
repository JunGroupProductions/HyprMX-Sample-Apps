package com.hyprmx.android.exampleapp

import android.os.Bundle
import android.view.Gravity
import android.widget.LinearLayout
import androidx.appcompat.app.AppCompatActivity
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_PLACEMENT_NAME
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_SIZE
import com.hyprmx.android.exampleapp.databinding.ActivityRecyclerBannerBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerSize
import com.hyprmx.android.sdk.banner.HyprMXBannerView

/**
 * This activity demonstrates how to integrate a banner using a recycler view.
 *
 * HyprMX recommends preloading the banners to ensure that the banners are ready when attached to
 * the view.
 *
 * The following example shows how to preload banners and attach them to the view.
 * This example uses the BannerRVAdapter which is the adapter used to attach views to the recycler.
 *
 */
class BannerRecyclerIntegrationActivity : AppCompatActivity() {

  private lateinit var binding: ActivityRecyclerBannerBinding
  private lateinit var recyclerViewItems: MutableList<HyprMXBannerView>

  companion object {
    // The number of banners to preload.  This should be greater than the number of banners that could
    // be visible on the screen at one time
    const val BANNER_COUNT = 5

    // The size of the recycler list
    const val BANNER_LIST_SIZE = 150

    // The frequency of the banner in the list.  This determines when to show a banner in the list.
    const val BANNER_FREQUENCY = 10
  }

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    binding = ActivityRecyclerBannerBinding.inflate(layoutInflater)
    setContentView(binding.root)

    recyclerViewItems = initBannerViews(BANNER_COUNT, BANNER_PLACEMENT_NAME, BANNER_SIZE)
    binding.bannerRv.adapter = BannerRVAdapter(
      BANNER_LIST_SIZE,
      BANNER_SIZE.width,
      BANNER_SIZE.height,
      BANNER_FREQUENCY,
      recyclerViewItems
    )
  }

  /**
   *
   * Preloads a list of banner views.
   *
   * @param count The number of banners to preload
   * @param placementName The name of the placement to preload.  In this case we are using the same placement name for each preloaded banner.
   * @param bannerSize The size of the banner to preload
   *
   */
  private fun initBannerViews(
    count: Int,
    placementName: String,
    bannerSize: HyprMXBannerSize
  ): MutableList<HyprMXBannerView> {
    val bannerViews = mutableListOf<HyprMXBannerView>()
    for (i in 0 until count) {
      val bv = HyprMXBannerView(
        context = this,
        attrs = null,
        placementName = placementName,
        adSize = bannerSize
      )
      // Add the banner to the ad view.
      val params = LinearLayout.LayoutParams(
        bv.context.dpToPx(bannerSize.width),
        bv.context.dpToPx(bannerSize.height)
      )
      params.gravity = Gravity.CENTER_HORIZONTAL
      bv.layoutParams = params
      bv.loadAd()
      bannerViews.add(bv)
    }
    return bannerViews
  }

  override fun onDestroy() {
    super.onDestroy()
    // HyprMX recommends calling destroy on the HyprMXBannerView
    // when you are no longer using the banner or the activity is being destroyed
    recyclerViewItems.forEach {
      it.destroy()
    }
    recyclerViewItems.clear()
  }
}

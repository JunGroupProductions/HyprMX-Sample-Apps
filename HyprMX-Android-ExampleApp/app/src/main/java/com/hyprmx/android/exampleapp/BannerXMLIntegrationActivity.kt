package com.hyprmx.android.exampleapp

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.hyprmx.android.exampleapp.databinding.ActivityXmlIntegrationBannerBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerListener

/**
 * This activity demonstrates how to integrate a banner using XML
 *
 * activity_xml_integration_banner.xml shows how to integrate using xml
 */
class BannerXMLIntegrationActivity : AppCompatActivity(), HyprMXBannerListener by HyprMXBannerListenerImpl() {

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
}

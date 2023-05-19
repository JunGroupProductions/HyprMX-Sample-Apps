package com.hyprmx.android.exampleapp

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.width
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.compose.ui.viewinterop.AndroidView
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_PLACEMENT_NAME
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_SIZE
import com.hyprmx.android.sdk.banner.HyprMXBannerView

/**
 * This activity demonstrates how to integrate a banner using JetPack Compose
 */
class BannerJetPackComposeActivity : ComponentActivity() {
  private lateinit var hyprMXBannerView: HyprMXBannerView
  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)

    hyprMXBannerView = HyprMXBannerView(this@BannerJetPackComposeActivity, null).apply {
      placementName = BANNER_PLACEMENT_NAME
      adSize = BANNER_SIZE
      loadAd()
    }

    setContent {
      BannerView()
    }
  }

  @Composable
  fun BannerView() {
    Column(
      modifier = Modifier.fillMaxSize(),
      verticalArrangement = Arrangement.Center,
      horizontalAlignment = Alignment.CenterHorizontally
    ) {
      AndroidView(
        factory = {
          hyprMXBannerView
        },
        modifier = Modifier
          .width(320.dp)
          .height(50.dp)
      )
    }
  }

  override fun onDestroy() {
    super.onDestroy()
    // HyprMX recommends calling destroy on the HyprMXBannerView
    // when you are no longer using the banner or the activity is being destroyed
    hyprMXBannerView.destroy()
  }
}

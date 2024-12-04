package com.hyprmx.android.exampleapp

import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.systemBarsPadding
import androidx.compose.foundation.layout.width
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.compose.ui.viewinterop.AndroidView
import androidx.compose.ui.viewinterop.NoOpUpdate
import androidx.lifecycle.lifecycleScope
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_PLACEMENT_NAME
import com.hyprmx.android.exampleapp.MainActivity.Companion.BANNER_SIZE
import com.hyprmx.android.sdk.banner.HyprMXBannerView
import kotlinx.coroutines.launch

/**
 * This activity demonstrates how to integrate a banner using JetPack Compose
 */
class BannerJetPackComposeActivity : ComponentActivity() {
  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)

    setContent {
      BannerView()
    }
  }

  @Composable
  private fun BannerView() {
    Box(
      modifier = Modifier
          .fillMaxSize()
          .systemBarsPadding(),
      contentAlignment = Alignment.Center
    ) {
      AndroidView(
        factory = { context ->
          HyprMXBannerView(context, null).apply {
            placementName = BANNER_PLACEMENT_NAME
            adSize = BANNER_SIZE
            lifecycleScope.launch {
              if (loadAd()) {
                Log.d(TAG, "onAdLoaded for $placementName")
              } else {
                Log.d(TAG, "onAdFailedToLoad for $placementName")
              }
            }
          }
        },
        onReset = NoOpUpdate,
        onRelease = { hyprMXBannerView ->
          // HyprMX recommends calling destroy on the HyprMXBannerView
          // when you are no longer using the banner or the activity is being destroyed
          hyprMXBannerView.destroy()
        },
        modifier = Modifier
            .width(320.dp)
            .height(50.dp)
      )
    }
  }

  companion object {
    const val TAG = "BJPCActivity"
  }
}

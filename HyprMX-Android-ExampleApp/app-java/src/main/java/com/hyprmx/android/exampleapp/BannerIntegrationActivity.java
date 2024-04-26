package com.hyprmx.android.exampleapp;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.hyprmx.android.exampleapp.databinding.ActivityIntegrationBannerBinding;

public class BannerIntegrationActivity extends AppCompatActivity {

  private ActivityIntegrationBannerBinding binding;

  private final String TAG = "BIActivity";

  public static void start(Context context) {
    Intent intent = new Intent(context, BannerIntegrationActivity.class);
    context.startActivity(intent);
  }

  @Override
  protected void onCreate(@Nullable Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    binding = ActivityIntegrationBannerBinding.inflate(getLayoutInflater());
    setContentView(binding.getRoot());

    // If you have not set the placement name or size in xml
    // you will need to set them here before calling load ad
    //
    // placementName = BANNER_PLACEMENT_NAME
    // adSize = HyprMXBannerSize.HyprMXAdSizeBanner
    binding.banner1.setListener(new HyprMXBannerListenerImpl());

    // This must be called after HyprMX has initialized or you will not get inventory
    binding.banner1.loadAd(loaded -> {
      if(loaded) {
        Log.d(TAG, "onAdLoaded for $placementName");
      } else {
        Log.d(TAG, "onAdFailedToLoad for $placementName");
      }
    });
  }

  @Override
  protected void onDestroy() {
    super.onDestroy();
    // HyprMX recommends calling destroy on the HyprMXBannerView
    // when you are no longer using the banner or the activity is being destroyed
    binding.banner1.setListener(null);
    binding.banner1.destroy();
  }
}

package com.hyprmx.android.exampleapp;

import android.util.Log;

import androidx.annotation.NonNull;

import com.hyprmx.android.sdk.banner.HyprMXBannerListener;
import com.hyprmx.android.sdk.banner.HyprMXBannerView;

public class HyprMXBannerListenerImpl implements HyprMXBannerListener {

  /**
   * Called when an user clicks on an ad for a given banner placement.
   */
  @Override
  public void onAdClicked(@NonNull HyprMXBannerView hyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdClicked for " + hyprMXBannerView.getPlacementName());
  }

  /**
   * Called when an ad is closed. Your application should resume here.
   */
  @Override
  public void onAdClosed(@NonNull HyprMXBannerView hyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdClosed for " + hyprMXBannerView.getPlacementName());
  }

  /**
   * Called when an user has navigated away from the app.
   */
  @Override
  public void onAdLeftApplication(@NonNull HyprMXBannerView hyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdLeftApplication for " + hyprMXBannerView.getPlacementName());
  }

  /**
   * Called when an user opens on an ad for a given banner placement.
   */
  @Override
  public void onAdOpened(@NonNull HyprMXBannerView hyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdOpened for " + hyprMXBannerView.getPlacementName());
  }

  /**
   * Called when an ad was impressed.
   */
  @Override
  public void onAdImpression(@NonNull HyprMXBannerView hyprMXBannerView) {
    Log.d(MainActivity.TAG, "onAdOpened for " + hyprMXBannerView.getPlacementName());
  }
}

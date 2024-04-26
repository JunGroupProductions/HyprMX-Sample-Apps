package com.hyprmx.android.exampleapp;

import static androidx.constraintlayout.widget.ConstraintSet.BOTTOM;
import static androidx.constraintlayout.widget.ConstraintSet.END;
import static androidx.constraintlayout.widget.ConstraintSet.START;
import static androidx.constraintlayout.widget.ConstraintSet.TOP;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.constraintlayout.widget.ConstraintSet;

import com.hyprmx.android.exampleapp.common.databinding.ActivityCodeIntegrationBannerBinding;
import com.hyprmx.android.sdk.banner.HyprMXBannerView;

public class BannerCodeIntegrationActivity extends AppCompatActivity {

  private ActivityCodeIntegrationBannerBinding binding = null;
  private HyprMXBannerView hyprMXBannerView = null;

  private static final String TAG = "BCIActivity";

  public static void start(Context context) {
    Intent intent = new Intent(context, BannerCodeIntegrationActivity.class);
    context.startActivity(intent);
  }

  @Override
  protected void onCreate(@Nullable Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    binding = ActivityCodeIntegrationBannerBinding.inflate(getLayoutInflater());
    setContentView(binding.getRoot());

    hyprMXBannerView = new HyprMXBannerView(this, null);
    hyprMXBannerView.setPlacementName(MainActivity.BANNER_PLACEMENT_NAME);
    hyprMXBannerView.setAdSize(MainActivity.BANNER_SIZE);
    hyprMXBannerView.setId(R.id.hyprmx_banner_view);

    // Set the size to the size of the requested banner
    ConstraintLayout.LayoutParams params = new ConstraintLayout.LayoutParams(Utilities.dpToPx(this, 320), Utilities.dpToPx(this, 50));
    hyprMXBannerView.setLayoutParams(params);

    hyprMXBannerView.loadAd(loaded -> {
      if(loaded) {
        Log.d(TAG, "onAdLoaded for $placementName");
      } else {
        Log.d(TAG, "onAdFailedToLoad for $placementName");
      }
    });
    binding.constraintLayout.addView(hyprMXBannerView);

    updateViewConstraints();
  }

  @Override
  protected void onDestroy() {
    // HyprMX recommends calling destroy on the HyprMXBannerView
    // when you are no longer using the banner or the activity is being destroyed
    hyprMXBannerView.destroy();
    hyprMXBannerView = null;
    super.onDestroy();
  }

  private void updateViewConstraints() {
    ConstraintSet cs = new ConstraintSet();
    cs.clone(binding.constraintLayout);
    cs.connect(R.id.hyprmx_banner_view, START, R.id.constraint_layout, START);
    cs.connect(R.id.hyprmx_banner_view, END, R.id.constraint_layout, END);
    cs.connect(R.id.hyprmx_banner_view, TOP, R.id.constraint_layout, TOP);
    cs.connect(R.id.hyprmx_banner_view, BOTTOM, R.id.constraint_layout, BOTTOM);

    // Apply the changes
    cs.applyTo(binding.constraintLayout);
  }
}

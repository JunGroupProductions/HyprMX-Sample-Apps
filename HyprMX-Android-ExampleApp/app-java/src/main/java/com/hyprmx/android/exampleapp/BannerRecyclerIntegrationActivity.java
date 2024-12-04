package com.hyprmx.android.exampleapp;

import static com.hyprmx.android.exampleapp.MainActivity.BANNER_PLACEMENT_NAME;
import static com.hyprmx.android.exampleapp.MainActivity.BANNER_SIZE;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.widget.LinearLayout;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.hyprmx.android.exampleapp.common.databinding.ActivityRecyclerBannerBinding;
import com.hyprmx.android.sdk.banner.HyprMXBannerSize;
import com.hyprmx.android.sdk.banner.HyprMXBannerView;

import java.util.ArrayList;
import java.util.List;

/**
 * This activity demonstrates how to integrate a banner using a recycler view.
 * <p>
 * HyprMX recommends preloading the banners to ensure that the banners are ready when attached to
 * the view.
 * <p>
 * The following example shows how to preload banners and attach them to the view.
 * This example uses the BannerRVAdapter which is the adapter used to attach views to the recycler.
 */
public class BannerRecyclerIntegrationActivity extends AppCompatActivity {

  // The number of banners to preload.  This should be greater than the number of banners that could
  // be visible on the screen at one time
  public static final int BANNER_COUNT = 5;

  // The size of the recycler list
  public static final int BANNER_LIST_SIZE = 150;

  // The frequency of the banner in the list.  This determines when to show a banner in the list.
  public static final int BANNER_FREQUENCY = 10;

  private List<HyprMXBannerView> recyclerViewItems;

  private static final String TAG = "BRIActivity";

  public static void start(Context context) {
    Intent intent = new Intent(context, BannerRecyclerIntegrationActivity.class);
    context.startActivity(intent);
  }

  @Override
  protected void onCreate(@Nullable Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    ActivityRecyclerBannerBinding binding = ActivityRecyclerBannerBinding.inflate(getLayoutInflater());
    Utilities.applyWindowInsets(binding.getRoot());
    setContentView(binding.getRoot());

    recyclerViewItems = initBannerViews(BANNER_SIZE);
    binding.bannerRv.setAdapter(new BannerRVAdapter(
      BANNER_LIST_SIZE,
      BANNER_FREQUENCY,
      recyclerViewItems
    ));
  }

  @Override
  protected void onDestroy() {
    super.onDestroy();
    // HyprMX recommends calling destroy on the HyprMXBannerView
    // when you are no longer using the banner or the activity is being destroyed
    for (HyprMXBannerView item : recyclerViewItems) {
      item.destroy();
    }
    recyclerViewItems.clear();
  }

  private List<HyprMXBannerView> initBannerViews(HyprMXBannerSize bannerSize) {
    ArrayList<HyprMXBannerView> bannerViews = new ArrayList<>();

    for (int i = 0; i < BANNER_COUNT; i++) {
      HyprMXBannerView bv = new HyprMXBannerView(this, null, BANNER_PLACEMENT_NAME, bannerSize);
      // Add the banner to the ad view.
      LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
        Utilities.dpToPx(this, bannerSize.getWidth()),
        Utilities.dpToPx(this, bannerSize.getHeight())
      );
      lp.gravity = Gravity.CENTER_HORIZONTAL;
      bv.setLayoutParams(lp);

      bv.loadAd(loaded -> {
        if(loaded) {
          Log.d(TAG, "onAdLoaded for $placementName");
        } else {
          Log.d(TAG, "onAdFailedToLoad for $placementName");
        }
      });

      bannerViews.add(bv);
    }
    return bannerViews;
  }
}

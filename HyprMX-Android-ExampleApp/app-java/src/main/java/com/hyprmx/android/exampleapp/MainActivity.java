package com.hyprmx.android.exampleapp;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;

import com.hyprmx.android.exampleapp.common.databinding.ActivityMainBinding;
import com.hyprmx.android.sdk.banner.HyprMXBannerSize;
import com.hyprmx.android.sdk.core.HyprMX;
import com.hyprmx.android.sdk.core.HyprMXErrors;
import com.hyprmx.android.sdk.core.HyprMXIf;
import com.hyprmx.android.sdk.core.InitResult;
import com.hyprmx.android.sdk.placement.HyprMXPlacementExpiryListener;
import com.hyprmx.android.sdk.placement.HyprMXRewardedShowListener;
import com.hyprmx.android.sdk.placement.HyprMXShowListener;
import com.hyprmx.android.sdk.placement.Placement;

public class MainActivity extends AppCompatActivity implements HyprMXShowListener, HyprMXPlacementExpiryListener,
  HyprMXRewardedShowListener {

  public static final String TAG = "HyprMX";

  private static final String DISTRIBUTOR_ID = "11000124103";

  private static final String INTERSTITIAL_PLACEMENT_NAME = "Mraid";
  private static final String REWARDED_PLACEMENT_NAME = "Webtraffic";
  public static final String BANNER_PLACEMENT_NAME = "banner_320_50";
  public static HyprMXBannerSize BANNER_SIZE = HyprMXBannerSize.HyprMXAdSizeBanner.INSTANCE;

  private ActivityMainBinding binding = null;

  private Placement interstitialPlacement = null;
  private Placement rewardedPlacement = null;

  @Override
  protected void onCreate(@Nullable Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    binding = ActivityMainBinding.inflate(getLayoutInflater());
    setContentView(binding.getRoot());

    setSupportActionBar(binding.toolbar);
    ActionBar ab = getSupportActionBar();
    if (ab != null) {
      ab.setDisplayShowTitleEnabled(false);
      ab.setLogo(R.drawable.hyprmx_logo);
    }

    binding.interstitialLabel.setText(INTERSTITIAL_PLACEMENT_NAME);
    binding.rewardedLabel.setText(REWARDED_PLACEMENT_NAME);
    binding.bannerLabel.setText(BANNER_PLACEMENT_NAME);
    binding.buttonShowCompose.setVisibility(View.GONE);

    setupClickListeners();

    HyprMXIf.HyprMXInitializationListener initializationListener = new HyprMXIf.HyprMXInitializationListener() {

      /**
       * If the SDK has failed to initialize, try the following:
       * <p>
       * Confirm your distributor ID is correct.
       * <p>
       * Enable debug logging
       *  HyprMXLog.enableDebugLogs(true)
       * <p>
       *  and check the logs for more information.
       */
      @Override
      public void onInitialized(@NonNull InitResult initResult) {
        if (initResult.isSuccess()) {
          // You can now request and show ads.
          Log.i(TAG, "initializationComplete");
          binding.messageView.setText(getString(R.string.initialization_completed));

          setupPlacements();
        } else {
          Log.i(TAG, "initializationFailed");
          binding.messageView.setText(getString(R.string.initialization_failed));
        }
      }
    };

    /*
     * The initializer no longer includes an optional ageRestrictedUser parameter. If the user is under the age of 16, set this parameter to true
     * by calling HyprMX.INSTANCE.setAgeRestrictedUser(true);.
     * Setting the ageRestrictedUser parameter is recommended for all users within applications that participate in Google Play’s Designed
     * for Families program, are listed in Google Play’s Family section, or include children as one of the target audiences to prevent access to
     * the AAID for end-users flagged as children.
     */
    HyprMX.INSTANCE.initialize(this, DISTRIBUTOR_ID, initializationListener);
  }

  private void setupPlacements() {
    interstitialPlacement = HyprMX.INSTANCE.getPlacement(INTERSTITIAL_PLACEMENT_NAME);
    interstitialPlacement.setPlacementExpiryListener(this);

    rewardedPlacement = HyprMX.INSTANCE.getPlacement(REWARDED_PLACEMENT_NAME);
    rewardedPlacement.setPlacementExpiryListener(this);
  }

  /**
   * Sets up the UI click listeners
   */
  private void setupClickListeners() {
    binding.buttonLoadInterstitial.setOnClickListener(v -> {
      if (interstitialPlacement != null) {
        interstitialPlacement.loadAd(isAdAvailable -> {
          onAdAvailable(interstitialPlacement, isAdAvailable);
        });
      }
    });

    binding.buttonShowInterstitial.setOnClickListener(v -> interstitialPlacement.showAd(this));

    binding.buttonLoadRewarded.setOnClickListener(v -> {
      if (rewardedPlacement != null) {
        rewardedPlacement.loadAd(isAdAvailable -> {
          onAdAvailable(rewardedPlacement, isAdAvailable);
        });
      }
    });

    binding.buttonShowRewarded.setOnClickListener(v -> rewardedPlacement.showAd(this));

    binding.buttonShowXml.setOnClickListener(v -> BannerIntegrationActivity.start(this));

    binding.buttonShowCode.setOnClickListener(v -> BannerCodeIntegrationActivity.start(this));

    binding.buttonShowRecycler.setOnClickListener(v -> BannerRecyclerIntegrationActivity.start(this));
  }

  public void onAdAvailable(Placement placement, boolean isAdAvailable) {
    if (isAdAvailable) {
      Log.i(TAG, "onAdAvailable for " + placement.getName());
      binding.messageView.setText(getString(R.string.ad_available, placement.getName()));
      updateShowButton(placement, true);
    } else {
      Log.i(TAG, "onAdNotAvailable for " + placement.getName());
      binding.messageView.setText(getString(R.string.ad_not_available, placement.getName()));
      updateShowButton(placement, false);
    }
  }

  /**
   * Updates the state of the show button
   */
  private void updateShowButton(Placement placement, boolean enabled) {
    if (placement == rewardedPlacement) {
      binding.buttonShowRewarded.setEnabled(enabled);
    } else if (placement == interstitialPlacement) {
      binding.buttonShowInterstitial.setEnabled(enabled);
    }
  }

  /**
   * Called when an ad is closed. Your application should resume here.
   */
  @Override
  public void onAdClosed(Placement placement, boolean finished) {
    Log.i(TAG, "onAdClosed for " + placement.getName());
    binding.messageView.setText(getString(R.string.ad_closed));
    updateShowButton(placement, false);
  }

  /**
   * Called when there was an error displaying the ad.
   */
  @Override
  public void onAdDisplayError(Placement placement, HyprMXErrors hyprMXError) {
    Log.i(TAG, "onAdDisplayError for " + placement.getName() + "with error $hyprMXError");
    binding.messageView.setText(getString(R.string.ad_error));
  }

  /**
   * Called when the user should be rewarded for the given rewarded placement.
   */
  @Override
  public void onAdRewarded(Placement placement, String rewardName, int rewardValue) {
    Log.i(TAG, "onAdRewarded for " + placement.getName());
    binding.messageView.setText(getString(R.string.ad_rewarded));
  }

  /**
   * Called when an ad is shown for the given placement.  Your application should pause here.
   */
  @Override
  public void onAdStarted(Placement placement) {
    Log.i(TAG, "onAdStarted for " + placement.getName());
    binding.messageView.setText(getString(R.string.ad_started));
  }

  @Override
  public void onAdExpired(Placement placement) {
    Log.i(TAG, "onAdExpired for " + placement.getName());
    binding.messageView.setText(getString(R.string.ad_expired, placement.getName()));
    updateShowButton(placement, false);
  }

  @Override
  public void onAdImpression(Placement placement) {
    Log.i(TAG, "onAdExpired for " + placement.getName());
    binding.messageView.setText(getString(R.string.ad_impressed, placement.getName()));
  }
}

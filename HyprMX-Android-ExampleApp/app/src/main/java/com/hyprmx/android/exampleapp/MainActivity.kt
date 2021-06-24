package com.hyprmx.android.exampleapp

import android.content.Context
import android.os.Bundle
import android.util.Log
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import com.hyprmx.android.exampleapp.databinding.ActivityMainBinding
import com.hyprmx.android.sdk.consent.ConsentStatus
import com.hyprmx.android.sdk.core.HyprMX
import com.hyprmx.android.sdk.core.HyprMXErrors
import com.hyprmx.android.sdk.core.HyprMXIf
import com.hyprmx.android.sdk.placement.Placement
import com.hyprmx.android.sdk.placement.PlacementListener
import com.hyprmx.android.sdk.placement.RewardedPlacementListener
import java.util.UUID

class MainActivity : AppCompatActivity(), PlacementListener, RewardedPlacementListener {

  companion object {
    const val TAG = "HyprMX"
    const val INTERSTITIAL_PLACEMENT_NAME = "Mraid"
    const val REWARDED_PLACEMENT_NAME = "Vast"
    const val DISTRIBUTOR_ID = "1000198877"
    val CONSENT_STATUS = ConsentStatus.CONSENT_STATUS_UNKNOWN
  }

  private lateinit var binding: ActivityMainBinding
  private var interstitialPlacement: Placement? = null
  private var rewardedPlacement: Placement? = null

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    binding = ActivityMainBinding.inflate(layoutInflater)
    setContentView(binding.root)

    setSupportActionBar(binding.toolbar)
    supportActionBar?.setDisplayShowTitleEnabled(false)
    supportActionBar?.setLogo(R.drawable.hyprmx_logo)

    val initializationListener = object : HyprMXIf.HyprMXInitializationListener {
      /**
       * Called when the SDK has successfully initialized.
       * You can now request and show ads.
       */
      override fun initializationComplete() {
        Log.i(TAG, "initializationComplete")
        interstitialPlacement = HyprMX.getPlacement(INTERSTITIAL_PLACEMENT_NAME).apply {
          setPlacementListener(this@MainActivity)
        }
        rewardedPlacement = HyprMX.getPlacement(REWARDED_PLACEMENT_NAME).apply {
          setPlacementListener(this@MainActivity)
        }
      }

      /**
       * Called when the SDK has failed to initialize.
       *
       * Confirm your distributor ID is correct.
       *
       * Enable debug logging
       *  HyprMXLog.enableDebugLogs(true)
       *
       *  and check the logs for more information.
       */
      override fun initializationFailed() {
        Log.i(TAG, "initializationFailed")
      }
    }

    HyprMX.initialize(this, DISTRIBUTOR_ID, getUserId(), CONSENT_STATUS, initializationListener)
  }

  fun onClickInterstitialLoadAd(view: View) {
    interstitialPlacement?.loadAd()
  }

  fun onClickInterstitialShowAd(view: View) {
    interstitialPlacement?.showAd()
  }

  fun onClickLoadRewarded(view: View) {
    rewardedPlacement?.loadAd()
  }

  fun onClickShowRewarded(view: View) {
    rewardedPlacement?.showAd()
  }

  /**
   * Example of how to generate a user id if you do not have one.
   *
   * This creates the user id and stores in in shared prefs for re-use
   */
  private fun getUserId(): String {
    val sharedPreferences = getSharedPreferences("hyprmx_prefs", Context.MODE_PRIVATE)
    var userID = sharedPreferences.getString("hyprUserId", null)
    if (userID == null) {
      userID = UUID.randomUUID().toString()
      sharedPreferences.edit().putString("hyprUserId", userID).apply()
    }
    return userID
  }

  // HyprMX Placement callbacks

  /**
   *  Called when an ad is available for the given placement.
   */
  override fun onAdAvailable(placement: Placement) {
    Log.i(TAG, "onAdAvailable for ${placement.name}")
  }

  /**
   * Called when an ad is closed. Your application should resume here.
   */
  override fun onAdClosed(placement: Placement, finished: Boolean) {
    Log.i(TAG, "onAdClosed for ${placement.name}")
  }

  /**
   * Called when there was an error displaying the ad.
   */
  override fun onAdDisplayError(placement: Placement, hyprMXError: HyprMXErrors) {
    Log.i(TAG, "onAdDisplayError for ${placement.name} with error $hyprMXError")
  }

  /**
   * Called when no ad is available for the given placement.
   */
  override fun onAdNotAvailable(placement: Placement) {
    Log.i(TAG, "onAdNotAvailable for ${placement.name}")
  }

  /**
   * Called when the user should be rewarded for the given rewarded placement.
   */
  override fun onAdRewarded(placement: Placement, rewardName: String, rewardValue: Int) {
    Log.i(TAG, "onAdRewarded for ${placement.name}")
  }

  /**
   * Called when an ad is shown for the given placement.  Your application should pause here.
   */
  override fun onAdStarted(placement: Placement) {
    Log.i(TAG, "onAdStarted for ${placement.name}")
  }
}

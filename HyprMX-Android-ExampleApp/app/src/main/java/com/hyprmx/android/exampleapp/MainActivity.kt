package com.hyprmx.android.exampleapp

import android.content.Context
import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.hyprmx.android.exampleapp.databinding.ActivityMainBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerSize
import com.hyprmx.android.sdk.consent.ConsentStatus
import com.hyprmx.android.sdk.core.HyprMX
import com.hyprmx.android.sdk.core.HyprMXErrors
import com.hyprmx.android.sdk.core.HyprMXIf
import com.hyprmx.android.sdk.placement.Placement
import com.hyprmx.android.sdk.placement.PlacementListener
import com.hyprmx.android.sdk.placement.RewardedPlacementListener
import java.util.UUID

/**
 * This activity demonstrates how to integrate Rewarded and Interstitial Ads
 */
class MainActivity : AppCompatActivity(), PlacementListener, RewardedPlacementListener {

  companion object {
    const val TAG = "HyprMX"

    const val DISTRIBUTOR_ID = "11000124103"

    const val INTERSTITIAL_PLACEMENT_NAME = "Mraid"
    const val REWARDED_PLACEMENT_NAME = "Vast"

    const val BANNER_PLACEMENT_NAME = "banner_320_50"
    val BANNER_SIZE = HyprMXBannerSize.HyprMXAdSizeBanner

    val CONSENT_STATUS = ConsentStatus.CONSENT_STATUS_UNKNOWN
  }

  private lateinit var binding: ActivityMainBinding
  private val interstitialPlacement: Placement by lazy {
    HyprMX.getPlacement(INTERSTITIAL_PLACEMENT_NAME).apply {
      setPlacementListener(this@MainActivity)
    }
  }
  private val rewardedPlacement: Placement by lazy {
    HyprMX.getPlacement(REWARDED_PLACEMENT_NAME).apply {
      setPlacementListener(this@MainActivity)
    }
  }

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    binding = ActivityMainBinding.inflate(layoutInflater)
    setContentView(binding.root)

    setSupportActionBar(binding.toolbar)
    supportActionBar?.apply {
      setDisplayShowTitleEnabled(false)
      setLogo(R.drawable.hyprmx_logo)
    }

    with(binding) {
      interstitialLabel.text = INTERSTITIAL_PLACEMENT_NAME
      rewardedLabel.text = REWARDED_PLACEMENT_NAME
      bannerLabel.text = BANNER_PLACEMENT_NAME
    }

    setupClickListeners()

    val initializationListener = object : HyprMXIf.HyprMXInitializationListener {
      /**
       * Called when the SDK has successfully initialized.
       * You can now request and show ads.
       */
      override fun initializationComplete() {
        Log.i(TAG, "initializationComplete")
        binding.messageView.text = getString(R.string.initialization_completed)
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
        binding.messageView.text = getString(R.string.initialization_failed)
      }
    }

    /**
     * The initializer includes an optional ageRestrictedUser parameter. If the user is under the age of 16, set this parameter to true.
     * Setting the ageRestrictedUser parameter is recommended for all users within applications that participate in Google Play’s Designed
     * for Families program, are listed in Google Play’s Family section, or include children as one of the target audiences to prevent access to
     * the AAID for end-users flagged as children.
     */
    HyprMX.initialize(this, DISTRIBUTOR_ID, getUserId(), CONSENT_STATUS, ageRestrictedUser = false, initializationListener)
  }

  /**
   * Sets up the UI click listeners
   */
  private fun setupClickListeners() {
    with(binding) {
      buttonLoadInterstitial.setOnClickListener {
        interstitialPlacement.loadAd()
      }

      buttonShowInterstitial.setOnClickListener {
        interstitialPlacement.showAd()
      }

      buttonLoadRewarded.setOnClickListener {
        rewardedPlacement.loadAd()
      }

      buttonShowRewarded.setOnClickListener {
        rewardedPlacement.showAd()
      }

      buttonShowXml.setOnClickListener {
        openActivity<BannerXMLIntegrationActivity>()
      }

      buttonShowCode.setOnClickListener {
        openActivity<BannerCodeIntegrationActivity>()
      }

      buttonShowRecycler.setOnClickListener {
        openActivity<BannerRecyclerIntegrationActivity>()
      }

      buttonShowCompose.setOnClickListener {
        openActivity<BannerJetPackComposeActivity>()
      }
    }
  }

  private inline fun <reified T> openActivity() {
    startActivity(Intent(this, T::class.java))
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
    binding.messageView.text = getString(R.string.ad_available, placement.name)
    updateShowButton(placement, true)
  }

  /**
   * Updates the state of the show button
   */
  private fun updateShowButton(placement: Placement, enabled: Boolean) {
    when (placement) {
      rewardedPlacement -> {
        binding.buttonShowRewarded.isEnabled = enabled
      }
      interstitialPlacement -> {
        binding.buttonShowInterstitial.isEnabled = enabled
      }
    }
  }

  /**
   * Called when an ad is closed. Your application should resume here.
   */
  override fun onAdClosed(placement: Placement, finished: Boolean) {
    Log.i(TAG, "onAdClosed for ${placement.name}")
    binding.messageView.text = getString(R.string.ad_closed)
    updateShowButton(placement, false)
  }

  /**
   * Called when there was an error displaying the ad.
   */
  override fun onAdDisplayError(placement: Placement, hyprMXError: HyprMXErrors) {
    Log.i(TAG, "onAdDisplayError for ${placement.name} with error $hyprMXError")
    binding.messageView.text = getString(R.string.ad_error)
  }

  /**
   * Called when no ad is available for the given placement.
   */
  override fun onAdNotAvailable(placement: Placement) {
    Log.i(TAG, "onAdNotAvailable for ${placement.name}")
    binding.messageView.text = getString(R.string.ad_not_available, placement.name)
    updateShowButton(placement, false)
  }

  /**
   * Called when the user should be rewarded for the given rewarded placement.
   */
  override fun onAdRewarded(placement: Placement, rewardName: String, rewardValue: Int) {
    Log.i(TAG, "onAdRewarded for ${placement.name}")
    binding.messageView.text = getString(R.string.ad_rewarded)
  }

  /**
   * Called when an ad is shown for the given placement.  Your application should pause here.
   */
  override fun onAdStarted(placement: Placement) {
    Log.i(TAG, "onAdStarted for ${placement.name}")
    binding.messageView.text = getString(R.string.ad_started)
  }

  override fun onAdExpired(placement: Placement) {
    Log.i(TAG, "onAdExpired for ${placement.name}")
    binding.messageView.text = getString(R.string.ad_expired, placement.name)
    updateShowButton(placement, false)
  }
}

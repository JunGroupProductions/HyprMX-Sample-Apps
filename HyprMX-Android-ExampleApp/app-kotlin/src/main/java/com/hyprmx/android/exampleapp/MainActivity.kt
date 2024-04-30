package com.hyprmx.android.exampleapp

import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.lifecycleScope
import com.hyprmx.android.exampleapp.common.databinding.ActivityMainBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerSize
import com.hyprmx.android.sdk.core.HyprMX
import com.hyprmx.android.sdk.core.HyprMXErrors
import com.hyprmx.android.sdk.placement.HyprMXPlacementExpiryListener
import com.hyprmx.android.sdk.placement.HyprMXRewardedShowListener
import com.hyprmx.android.sdk.placement.HyprMXShowListener
import com.hyprmx.android.sdk.placement.Placement
import kotlinx.coroutines.launch

/**
 * This activity demonstrates how to integrate Rewarded and Interstitial Ads
 */
class MainActivity : AppCompatActivity(), HyprMXShowListener, HyprMXPlacementExpiryListener,
  HyprMXRewardedShowListener {

  companion object {
    const val TAG = "HyprMX"

    const val DISTRIBUTOR_ID = "11000124103"

    const val INTERSTITIAL_PLACEMENT_NAME = "Mraid"
    const val REWARDED_PLACEMENT_NAME = "Webtraffic"

    const val BANNER_PLACEMENT_NAME = "banner_320_50"
    val BANNER_SIZE = HyprMXBannerSize.HyprMXAdSizeBanner
    const val USE_SUSPENDED_API_MODE = false
  }

  private lateinit var binding: ActivityMainBinding
  private val interstitialPlacement: Placement by lazy {
    HyprMX.getPlacement(INTERSTITIAL_PLACEMENT_NAME).apply {
      setPlacementExpiryListener(this@MainActivity)
    }
  }
  private val rewardedPlacement: Placement by lazy {
    HyprMX.getPlacement(REWARDED_PLACEMENT_NAME).apply {
      setPlacementExpiryListener(this@MainActivity)
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

    /*
     * The initializer no longer includes an optional ageRestrictedUser parameter. If the user is under the age of 16, set this parameter to true
     * by calling HyprMX.setAgeRestrictedUser(true)
     * Setting the ageRestrictedUser parameter is recommended for all users within applications that participate in Google Play’s Designed
     * for Families program, are listed in Google Play’s Family section, or include children as one of the target audiences to prevent access to
     * the AAID for end-users flagged as children.
     */
    if (USE_SUSPENDED_API_MODE) {
      lifecycleScope.launch {
        val (initSuccess, _) = HyprMX.initialize(this@MainActivity, DISTRIBUTOR_ID)
        handleInitialization(initSuccess)
      }
    } else {
      HyprMX.initialize(this@MainActivity, DISTRIBUTOR_ID) { (initSuccess, _) ->
        handleInitialization(initSuccess)
      }
    }
  }

  private fun handleInitialization(initSuccess: Boolean) {
    if (initSuccess) {
      // You can now request and show ads.
      Log.i(TAG, "initializationComplete")
      binding.messageView.text = getString(R.string.initialization_completed)
    } else {
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
      Log.i(TAG, "initializationFailed")
      binding.messageView.text = getString(R.string.initialization_failed)
    }
  }

  private fun Placement.load() {
    if (USE_SUSPENDED_API_MODE) {
      lifecycleScope.launch {
        loadAd().also { isAdAvailable ->
          onAdAvailable(this@load, isAdAvailable)
        }
      }
    } else {
      loadAd { isAdAvailable ->
        onAdAvailable(this@load, isAdAvailable)
      }
    }
  }

  /**
   * Sets up the UI click listeners
   */
  private fun setupClickListeners() {
    with(binding) {
      buttonLoadInterstitial.setOnClickListener {
        interstitialPlacement.load()
      }

      buttonShowInterstitial.setOnClickListener {
        interstitialPlacement.showAd(this@MainActivity)
      }

      buttonLoadRewarded.setOnClickListener {
        rewardedPlacement.load()
      }

      buttonShowRewarded.setOnClickListener {
        rewardedPlacement.showAd(this@MainActivity)
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

  private fun onAdAvailable(placement: Placement, isAdAvailable: Boolean) {
    if (isAdAvailable) {
      Log.i(TAG, "onAdAvailable for ${placement.name}")
      binding.messageView.text = getString(R.string.ad_available, placement.name)
      updateShowButton(placement, true)
    } else {
      Log.i(TAG, "onAdNotAvailable for ${placement.name}")
      binding.messageView.text = getString(R.string.ad_not_available, placement.name)
      updateShowButton(placement, false)
    }
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

  override fun onAdImpression(placement: Placement) {
    Log.i(TAG, "onAdExpired for ${placement.name}")
    binding.messageView.text = getString(R.string.ad_impressed, placement.name)
  }
}

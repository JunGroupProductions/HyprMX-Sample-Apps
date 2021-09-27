package com.hyprmx.android.exampleapp

import android.util.Log
import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.recyclerview.widget.RecyclerView
import com.hyprmx.android.exampleapp.databinding.BannerItemBinding
import com.hyprmx.android.exampleapp.databinding.ItemBannerTextBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerView

class BannerRVAdapter(
  private val listSize: Int,
  private val bannerWidth: Int,
  private val bannerHeight: Int,
  private val frequency: Int,
  private val bannerAds: List<HyprMXBannerView>
) : RecyclerView.Adapter<RecyclerView.ViewHolder>() {

  companion object {
    const val BANNER_TYPE = 0
    const val TEXT_TYPE = 1
  }

  class TextViewHolder(val itemViewBinding: ItemBannerTextBinding, width: Int, height: Int) :
    RecyclerView.ViewHolder(itemViewBinding.root) {
    init {
      val params = itemViewBinding.bannerMessages.layoutParams as ConstraintLayout.LayoutParams
      params.height = itemView.context.dpToPx(height)
      params.width = itemView.context.dpToPx(width)
    }
  }

  class BannerViewHolder(val itemViewBinding: BannerItemBinding) :
    RecyclerView.ViewHolder(itemViewBinding.root)

  override fun getItemViewType(position: Int): Int {
    if (position % frequency == 0) {
      return BANNER_TYPE
    }
    return TEXT_TYPE
  }

  override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): RecyclerView.ViewHolder {
    when (viewType) {
      BANNER_TYPE -> return BannerViewHolder(
        BannerItemBinding.inflate(
          LayoutInflater.from(parent.context),
          parent,
          false
        )
      )
      TEXT_TYPE -> return TextViewHolder(
        ItemBannerTextBinding.inflate(
          LayoutInflater.from(parent.context),
          parent,
          false
        ),
        bannerWidth, bannerHeight
      )
    }
    throw IllegalArgumentException("invalid view type $viewType")
  }

  override fun onBindViewHolder(holder: RecyclerView.ViewHolder, position: Int) {
    when (holder) {
      is TextViewHolder -> {
        holder.itemViewBinding.bannerMessages.text = "Cell Item $position"
      }
      is BannerViewHolder -> {
        val size = bannerAds.size
        val selectedBanner = (position / frequency) % size
        Log.d(
          MainActivity.TAG,
          """
            bannerListSize: $size
            position: $position
            selectedBanner: $selectedBanner
        """
        )

        val bannerView = bannerAds[selectedBanner]
        val root = holder.itemViewBinding.root

        if (root.childCount > 0) {
          root.removeAllViews()
        }
        if (bannerView.parent != null) {
          (bannerView.parent as ViewGroup).removeView(bannerView)
        }

        // Add the banner ad to the ad view.
        root.addView(bannerView)
      }
    }
  }

  override fun getItemCount(): Int {
    return listSize
  }
}

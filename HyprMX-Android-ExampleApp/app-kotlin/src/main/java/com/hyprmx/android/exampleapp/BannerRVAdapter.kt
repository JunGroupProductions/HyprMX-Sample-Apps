package com.hyprmx.android.exampleapp

import android.util.Log
import android.view.ViewGroup
import androidx.core.view.isNotEmpty
import androidx.recyclerview.widget.RecyclerView
import com.hyprmx.android.exampleapp.common.databinding.BannerItemBinding
import com.hyprmx.android.exampleapp.common.databinding.ItemBannerTextBinding
import com.hyprmx.android.sdk.banner.HyprMXBannerView

class BannerRVAdapter(
  private val listSize: Int,
  private val frequency: Int,
  private val bannerAds: List<HyprMXBannerView>
) : RecyclerView.Adapter<RecyclerView.ViewHolder>() {

  companion object {
    const val BANNER_TYPE = 0
    const val TEXT_TYPE = 1
  }

  class TextViewHolder(val itemViewBinding: ItemBannerTextBinding) :
    RecyclerView.ViewHolder(itemViewBinding.root)

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
          parent.context.layoutInflater(),
          parent,
          false
        )
      )
      TEXT_TYPE -> return TextViewHolder(
        ItemBannerTextBinding.inflate(
          parent.context.layoutInflater(),
          parent,
          false
        )
      )
    }
    throw IllegalArgumentException("invalid view type $viewType")
  }

  override fun onBindViewHolder(holder: RecyclerView.ViewHolder, position: Int) {
    when (holder) {
      is TextViewHolder -> {
        holder.itemViewBinding.bannerMessages.text = holder.itemView.context.getString(R.string.cell_item, position)
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

        if (root.isNotEmpty()) {
          root.removeAllViews()
        }

        (bannerView.parent as? ViewGroup)?.removeView(bannerView)

        // Add the banner ad to the ad view.
        root.addView(bannerView)
      }
    }
  }

  override fun getItemCount(): Int {
    return listSize
  }
}

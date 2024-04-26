package com.hyprmx.android.exampleapp;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.ViewGroup;
import android.widget.LinearLayout;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.hyprmx.android.exampleapp.common.databinding.BannerItemBinding;
import com.hyprmx.android.exampleapp.common.databinding.ItemBannerTextBinding;
import com.hyprmx.android.sdk.banner.HyprMXBannerView;

import java.util.List;

public class BannerRVAdapter extends RecyclerView.Adapter<RecyclerView.ViewHolder> {


  private static final int BANNER_TYPE = 0;
  private static final int TEXT_TYPE = 1;

  private final int listSize;
  private final int frequency;
  private final List<HyprMXBannerView> bannerAds;

  public BannerRVAdapter(int listSize, int frequency, List<HyprMXBannerView> bannerAds) {
    this.listSize = listSize;
    this.frequency = frequency;
    this.bannerAds = bannerAds;
  }

  @NonNull
  @Override
  public RecyclerView.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
    return switch (viewType) {
      case BANNER_TYPE -> new BannerViewHolder(
        BannerItemBinding.inflate(
          LayoutInflater.from(parent.getContext()),
          parent,
          false
        )
      );
      case TEXT_TYPE -> new TextViewHolder(
        ItemBannerTextBinding.inflate(
          LayoutInflater.from(parent.getContext()),
          parent,
          false
        )
      );
      default -> throw new IllegalArgumentException("invalid view type $viewType");
    };
  }

  @Override
  public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {
    if (holder instanceof TextViewHolder) {
      ((TextViewHolder) holder).getItemViewBinding().bannerMessages.setText(holder.itemView.getContext().getString(R.string.cell_item, position));
    } else if (holder instanceof BannerViewHolder) {
      int size = bannerAds.size();
      int selectedBanner = (position / frequency) % size;
      Log.d(
        MainActivity.TAG,
        """
              bannerListSize: $size
              position: $position
              selectedBanner: $selectedBanner
          """
      );

      HyprMXBannerView bannerView = bannerAds.get(selectedBanner);
      LinearLayout root = ((BannerViewHolder) holder).getItemBannerBinding().getRoot();

      if (isNotEmpty(root)) {
        root.removeAllViews();
      }

      ViewGroup bannerViewParent = (ViewGroup) bannerView.getParent();
      if(bannerViewParent != null) {
        bannerViewParent.removeView(bannerView);
      }

      // Add the banner ad to the ad view.
      root.addView(bannerView);
    }
  }

  private boolean isNotEmpty(LinearLayout ll) {
    return ll.getChildCount() != 0;
  }

  @Override
  public int getItemViewType(int position) {
    if (position % frequency == 0) {
      return BANNER_TYPE;
    }
    return TEXT_TYPE;
  }

  @Override
  public int getItemCount() {
    return listSize;
  }

  static class TextViewHolder extends RecyclerView.ViewHolder {

    private final ItemBannerTextBinding itemViewBinding;

    public TextViewHolder(@NonNull ItemBannerTextBinding itemViewBinding) {
      super(itemViewBinding.getRoot());
      this.itemViewBinding = itemViewBinding;
    }

    public ItemBannerTextBinding getItemViewBinding() {
      return itemViewBinding;
    }
  }

  static class BannerViewHolder extends RecyclerView.ViewHolder {
    private final BannerItemBinding itemBannerBinding;

    public BannerViewHolder(@NonNull BannerItemBinding itemBannerBinding) {
      super(itemBannerBinding.getRoot());
      this.itemBannerBinding = itemBannerBinding;
    }

    public BannerItemBinding getItemBannerBinding() {
      return itemBannerBinding;
    }
  }
}

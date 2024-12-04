package com.hyprmx.android.exampleapp;

import android.content.Context;
import android.util.TypedValue;
import android.view.View;

import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class Utilities {

  public static int dpToPx(Context context, int dp) {
    return (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp, context.getResources().getDisplayMetrics());
  }

  public static void applyWindowInsets(View view) {
    applyWindowInsets(view, WindowInsetsCompat.Type.systemBars() | WindowInsetsCompat.Type.displayCutout());
  }

  public static void applyWindowInsets(View view, int insetTypes) {
    ViewCompat.requestApplyInsets(view);

    ViewCompat.setOnApplyWindowInsetsListener(view, (v, insets) -> {
      Insets bars = insets.getInsets(insetTypes);

      v.setPadding(bars.left, bars.top, bars.right, bars.bottom);
      return WindowInsetsCompat.CONSUMED;
    });
  }
}

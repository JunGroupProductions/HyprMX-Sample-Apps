package com.hyprmx.android.exampleapp;

import android.content.Context;
import android.util.TypedValue;

public class Utilities {

  public static int dpToPx(Context context, int dp) {
    return (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp, context.getResources().getDisplayMetrics());
  }
}

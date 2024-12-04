package com.hyprmx.android.exampleapp

import android.content.Context
import android.util.TypedValue
import android.view.LayoutInflater
import android.view.View
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.core.view.updatePadding

fun Context.dpToPx(dp: Int): Int =
  TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp.toFloat(), resources.displayMetrics)
    .toInt()

fun Context.layoutInflater(): LayoutInflater = LayoutInflater.from(this)

fun View.applyWindowInsets(insetsType: Int = WindowInsetsCompat.Type.systemBars() or WindowInsetsCompat.Type.displayCutout()) {
  ViewCompat.requestApplyInsets(this)

  ViewCompat.setOnApplyWindowInsetsListener(this) { view, insets ->
    val bars = insets.getInsets(insetsType)

    view.updatePadding(
      left = bars.left,
      top = bars.top,
      right = bars.right,
      bottom = bars.bottom,
    )

    WindowInsetsCompat.CONSUMED
  }
}

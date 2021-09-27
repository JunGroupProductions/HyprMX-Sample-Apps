package com.hyprmx.android.exampleapp

import android.content.Context
import android.util.TypedValue

fun Context.dpToPx(dp: Int): Int =
  TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp.toFloat(), resources.displayMetrics)
    .toInt()

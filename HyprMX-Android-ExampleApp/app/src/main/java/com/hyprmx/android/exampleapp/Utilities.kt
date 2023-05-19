package com.hyprmx.android.exampleapp

import android.content.Context
import android.util.TypedValue
import android.view.LayoutInflater

fun Context.dpToPx(dp: Int): Int =
  TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp.toFloat(), resources.displayMetrics)
    .toInt()

fun Context.layoutInflater(): LayoutInflater = LayoutInflater.from(this)

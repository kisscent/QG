package com.blessall05.week1demo;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class ItemAdapt extends RecyclerView.Adapter<ItemAdapt.ViewHolder> {
    private final List<String> mItemList;
    public ItemAdapt(List<String> itemList) {
        mItemList = itemList;
    }

    static class ViewHolder extends RecyclerView.ViewHolder {
        TextView itemNumber, itemText;
        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            itemNumber = itemView.findViewById(R.id.item_number);
            itemText = itemView.findViewById(R.id.item_text);
        }
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.itemNumber.setText(String.valueOf(position + 1));
        holder.itemText.setText(mItemList.get(position));
    }

    @Override
    public int getItemCount() {
        return mItemList.size();
    }
}

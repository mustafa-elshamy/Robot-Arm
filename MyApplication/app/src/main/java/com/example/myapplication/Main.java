package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Main extends AppCompatActivity {

    public static String EXTRA_DEVICE_ADDRESS;
    private Button acc,btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);

        EXTRA_DEVICE_ADDRESS = getIntent().getStringExtra(DeviceListActivity.EXTRA_DEVICE_ADDRESS);

        acc = (Button) findViewById(R.id.acc);
        btn = (Button) findViewById(R.id.btn);

        acc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(Main.this,MainActivity.class);
                intent.putExtra(EXTRA_DEVICE_ADDRESS, EXTRA_DEVICE_ADDRESS);
                startActivity(intent);
            }
        });

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(Main.this,MainActivity2.class);
                intent.putExtra(EXTRA_DEVICE_ADDRESS, EXTRA_DEVICE_ADDRESS);
                startActivity(intent);
            }
        });
    }
}
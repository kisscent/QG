package com.blessall05.week1demo;

import android.os.Bundle;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    List<String> itemList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        initItem();

        RecyclerView recyclerView = findViewById(R.id.recyclerview);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        ItemAdapt adapter = new ItemAdapt(itemList);
        recyclerView.setAdapter(adapter);
    }

    private void initItem() {
        String text = getTextString();
        String[] items = text.split("\n");
        itemList.addAll(Arrays.asList(items));
    }

    private String getTextString() {
        String text = "羊有跪乳之恩，鸦有反哺之义。\n" +
                "见善如不及，见不善如探汤。\n" +
                "当仁，不让于师。\n" +
                "人不知而不愠，不亦君子乎？\n" +
                "言必信，行必果。\n" +
                "君子求诸己，小人求诸人。\n" +
                "君子坦荡荡，小人长戚戚。\n" +
                "不怨天，不尤人。\n" +
                "不迁怒，不贰过。\n" +
                "小不忍，则乱大谋。\n" +
                "小人之过也必文。\n" +
                "过而不改，是谓过矣。\n" +
                "君子务本，本立而道生。\n" +
                "君子耻其言而过其行。\n" +
                "三思而后行。\n" +
                "多行不义必自毙。\n" +
                "人谁无过，过而能改，善莫大焉。\n" +
                "不以一眚掩大德。\n" +
                "人一能之，己百之；人十能之，己千之。\n" +
                "知耻近乎勇。\n" +
                "以五十步笑百步。\n" +
                "君子莫大乎与人为善。\n" +
                "人皆可以为尧舜。\n" +
                "千丈之堤，以蝼蚁之穴溃；百尺之室，以突隙之烟焚。\n" +
                "言之者无罪，闻之者足以戒。\n" +
                "良药苦于口而利于病，忠言逆于耳而利于行。\n" +
                "良言一句三冬暖，恶语伤人六月寒。\n" +
                "千经万典，孝悌为先。\n" +
                "善恶随人作，祸福自己招。\n" +
                "学而不思罔，思而不学则殆。\n" +
                "知之为知之，不知为不知，是知也。\n" +
                "业精于勤，荒于嬉；行成于思，毁于随。\n" +
                "读书有三到：谓心到，眼到，口到。\n" +
                "学而不厌，诲人不倦。\n" +
                "不积跬步，无以至千里，不积小流，无以成江海。\n" +
                "欲穷千里目，更上一层楼。\n" +
                "强中自有强中手，莫向人前满自夸。\n" +
                "玉不琢，不成器；人不学，不知道。\n" +
                "黑发不知勤学早，白首方悔读书迟。\n" +
                "知不足者好学，耻下问者自满。\n" +
                "学不可以已。\n" +
                "学而时习之，不亦悦乎？\n" +
                "温故而知新，可以为师矣。\n" +
                "读书破万卷，下笔如有神。\n" +
                "少壮不努力，老大徒伤悲。\n" +
                "读书百遍而义自见。\n" +
                "学而不化，非学也。\n" +
                "好学而不贰。\n" +
                "学如不及，犹恐失之。\n" +
                "人而不学，其犹正墙面而立。\n" +
                "知而好问，然后能才。\n" +
                "学之广在于不倦，不倦在于固志。\n" +
                "学而不知道，与不学同；知而不能行，与不知同。\n" +
                "博观而约取，厚积而薄发。\n" +
                "差之毫厘，缪以千里。\n" +
                "盛年不重来，一日难再晨。\n" +
                "言之无文，行而不远。\n" +
                "人之为学，不可自小，又不可自大。\n" +
                "好学近乎知，力行近乎仁，知耻近乎勇。\n" +
                "书到用时方恨少，事非经过不知难。\n" +
                "笨鸟先飞早入林，笨人勤学早成材。\n" +
                "书山有路勤为径，学海无涯苦作舟。\n" +
                "学如逆水行舟，不进则退。\n" +
                "吾生也有涯而，知也无涯。\n" +
                "天下兴亡，匹夫有责。\n" +
                "生于忧患，死于安乐。\n" +
                "位卑未敢忘国。\n" +
                "人生自古谁无死，留取丹心照汉青。\n" +
                "先天下之忧而忧，后天下乐而乐。\n" +
                "小来思报国，不是爱封侯。\n" +
                "有益国家之事虽死弗避。\n" +
                "一寸山河一寸金。\n" +
                "欲安其家，必先安于国。\n" +
                "捐躯赴国难，视死忽如归。\n" +
                "风声、雨声、读书声，声声入耳；家事、国事、天下事，事事关心。\n" +
                "生当作人杰，死亦为鬼雄。\n" +
                "利于国者爱之，害于国者恶之。\n" +
                "读书本意在元元。\n" +
                "时穷节乃现，一一垂丹青。\n" +
                "哀哀父母，生我劬劳。\n" +
                "报国之心，死而后已。\n" +
                "忧国忘家，捐躯济难，忠臣之志也。\n" +
                "大丈夫处世，当扫除天下，安事一室乎？\n" +
                "君子之交淡如水，小人之交甘若醴。\n" +
                "老吾老，以及人之老；幼吾幼，以及人之幼。\n" +
                "见侮而不斗，辱也。\n" +
                "天下皆知取之为取，而莫知与之为取。\n" +
                "人固有一死，死或重于泰山，或轻于鸿毛。\n" +
                "天行健，君子以自强不息。";

        // 以下代码只在JAVA15 以上可用
        /*String text = """
                        羊有跪乳之恩，鸦有反哺之义。
                        见善如不及，见不善如探汤。
                        当仁，不让于师。
                        人不知而不愠，不亦君子乎？
                        言必信，行必果。
                        君子求诸己，小人求诸人。
                        君子坦荡荡，小人长戚戚。
                        不怨天，不尤人。
                        不迁怒，不贰过。
                        小不忍，则乱大谋。
                        小人之过也必文。
                        过而不改，是谓过矣。
                        君子务本，本立而道生。
                        君子耻其言而过其行。
                        三思而后行。
                        多行不义必自毙。
                        人谁无过，过而能改，善莫大焉。
                        不以一眚掩大德。
                        人一能之，己百之；人十能之，己千之。
                        知耻近乎勇。
                        以五十步笑百步。
                        君子莫大乎与人为善。
                        人皆可以为尧舜。
                        千丈之堤，以蝼蚁之穴溃；百尺之室，以突隙之烟焚。
                        言之者无罪，闻之者足以戒。
                        良药苦于口而利于病，忠言逆于耳而利于行。
                        良言一句三冬暖，恶语伤人六月寒。
                        千经万典，孝悌为先。
                        善恶随人作，祸福自己招。
                        学而不思罔，思而不学则殆。
                        知之为知之，不知为不知，是知也。
                        业精于勤，荒于嬉；行成于思，毁于随。
                        读书有三到：谓心到，眼到，口到。
                        学而不厌，诲人不倦。
                        不积跬步，无以至千里，不积小流，无以成江海。
                        欲穷千里目，更上一层楼。
                        强中自有强中手，莫向人前满自夸。
                        玉不琢，不成器；人不学，不知道。
                        黑发不知勤学早，白首方悔读书迟。
                        知不足者好学，耻下问者自满。
                        学不可以已。
                        学而时习之，不亦悦乎？
                        温故而知新，可以为师矣。
                        读书破万卷，下笔如有神。
                        少壮不努力，老大徒伤悲。
                        读书百遍而义自见。
                        学而不化，非学也。
                        好学而不贰。
                        学如不及，犹恐失之。
                        人而不学，其犹正墙面而立。
                        知而好问，然后能才。
                        学之广在于不倦，不倦在于固志。
                        学而不知道，与不学同；知而不能行，与不知同。
                        博观而约取，厚积而薄发。
                        差之毫厘，缪以千里。
                        盛年不重来，一日难再晨。
                        言之无文，行而不远。
                        人之为学，不可自小，又不可自大。
                        好学近乎知，力行近乎仁，知耻近乎勇。
                        书到用时方恨少，事非经过不知难。
                        笨鸟先飞早入林，笨人勤学早成材。
                        书山有路勤为径，学海无涯苦作舟。
                        学如逆水行舟，不进则退。
                        吾生也有涯而，知也无涯。
                        天下兴亡，匹夫有责。
                        生于忧患，死于安乐。
                        位卑未敢忘国。
                        人生自古谁无死，留取丹心照汉青。
                        先天下之忧而忧，后天下乐而乐。
                        小来思报国，不是爱封侯。
                        有益国家之事虽死弗避。
                        一寸山河一寸金。
                        欲安其家，必先安于国。
                        捐躯赴国难，视死忽如归。
                        风声、雨声、读书声，声声入耳；家事、国事、天下事，事事关心。
                        生当作人杰，死亦为鬼雄。
                        利于国者爱之，害于国者恶之。
                        读书本意在元元。
                        时穷节乃现，一一垂丹青。
                        哀哀父母，生我劬劳。
                        报国之心，死而后已。
                        忧国忘家，捐躯济难，忠臣之志也。
                        大丈夫处世，当扫除天下，安事一室乎？
                        君子之交淡如水，小人之交甘若醴。
                        老吾老，以及人之老；幼吾幼，以及人之幼。
                        见侮而不斗，辱也。
                        天下皆知取之为取，而莫知与之为取。
                        人固有一死，死或重于泰山，或轻于鸿毛。
                        天行健，君子以自强不息。
                """;*/

        return text;
    }
}


#include "scene_list.h"
#include <cstdlib>
#include <time.h>

void mainGame4(GameScenes *gameScenes) {
	Scene *scene = gameScenes->newScene("mainGame4");
	gameScenes->addScene(scene);

	Container *sceneContainer = scene->getSceneContainer();
	RendererController *SDLRendererController = gameScenes->getRendererController();
	SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

	const GameProp GAME_PROP = gameScenes->getGameProp();

	SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bG_main.png");
	SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Gob2.png");
	SDL_Texture *gameTrue = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/true.png");
	SDL_Texture *gameFalse = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/false.png");
	SDL_Texture *kob1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame4/kob.png");
	SDL_Texture *kob2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame4/Kob 2.png");

	std::function<std::function<void(Touchable *, ComponentPosition, SDL_Event)>()> doNothing
			= []() {
				return [](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {};
			};

	auto *timer = new Timer();

	int *score = new int{0};
	bool *answering = new bool{false};
	bool *answer = new bool[4];

	typedef struct {
		Button *Q = nullptr;
		Button *A[4] = {nullptr, nullptr, nullptr, nullptr};
	} Question;

	auto questions = new Question[25];

	const std::string *questionTitle = new std::string[25]{
			"การจัดการทรัพยากรน้ำในชุมชนที่ดีที่สุดคือข้อใด",
			"สาเหตุสำคัญที่ทำให้เกิดภาวะโลกร้อนคืออะไร",
			"กลไกที่ทำให้โลกเรารักษาพลังงานความร้อนไว้ได้คืออะไร",
			"ก๊าซในข้อใดที่ก่อให้เกิดปรากฏการณ์เรือนกระจกทั้งหมด ",
			"รังสีที่ทำให้โลกร้อนขึ้นคือรังสีชนิดใด ",
			"ก๊าซมีเทนมีแหล่งที่มาจากที่ใด ",
			"ข้อใดไม่ใช่ผลกระทบจากภาวะโลกร้อน ",
			"การปฏิบัติในข้อใดก่อให้เกิดมลภาวะของอากาศน้อยที่สุด",
			"ข้อใดไม่ใช่การป้องกันและแก้ไขปัญหาสภาวะโลกร้อน",
			"ข้อใดไม่ใช่แนวทางในการแก้ปัญหาทรัพยากรดิน ",
			"การกระทำใดต่อไปลดปริมาณก๊าซคาร์บอนไดออกไซด์ได้มากที่สุด",
			"การทำเกษตรกรรมที่ใช้ปุ่ยเคมีก่อให้เกิดแก๊สเรือนกระจกในข้อใด",
			"โฟม สเปรย์มีส่วนทำให้เกิดแก๊สเรือนกระจกในข้อใด",
			"ข้อใดไม่ใช่ผลกระทบจากการเกิดปรากฏการณ์เรือนกระจก",
			"สาเหตุสำคัญข้อใดมีการเพิ่มขึ้นของแก๊สต่างๆ",
			"กลุ่มกิจกรรมด้านใดปลดปล่อยแก๊สเรือนกระจกมากที่สุด",
			"ข้อใดเป็นการลดภาวะโลกร้อนได้ดีที่สุด",
			"ภัยธรรมชาติที่จะเกิดตามมากับภาวะโลกร้อนที่เห็นได้ชัดที่สุดคืออะไร",
			"ข้อใดไม่ใช่วิธีการอนุรักษ์สิ่งแวดล้อมและทรัพยากรธรรมชาติ",
			"การกระทำในข้อใดไม่ก่อให้เกิดมลพิษในดิน",
			"แก๊สคาร์บอนมอนอกไซด์ ส่งผลกระทบต่อสิ่งมีชีวิตอย่างไร ",
			"วิธีการช่วยอนุรักษ์ทรัพยากรป่าไม้ให้ได้ผลยั่งยืนมากที่สุดคือข้อใด",
			"วิธีการใดที่จะช่วยรักษาป่าไม้ให้คงอยู่ได้อย่างยั่งยืน ",
			"การป้องกันการตัดไม้เป็นการป้องกันปัญหาการขาดแคลนน้ำหรือไม่",
			"ข้อใดเป็นการอนุรักษ์ทรัพยากรธรรมชาติ "

	};

	const std::string *answer1Title = new std::string[25]{
			"การใช้น้ำอย่างประหยัด",
			"ก๊าซคาร์บอนไดออกไซด์ ",
			"ปรากฏการณ์เรือนกระจก",
			"คาร์บอนไดออกไซด์ ,co ,มีเทน",
			"รังสีเอ็กซ์และรังสีอัลตราไวโอเลต",
			"จากกระบวนการหายใจของสิ่งมีชีวิต",
			"ทำให้ทะเลทรายตอนกลางวันอากาศเย็นขึ้น",
			"ใช้เครื่องยนต์มีกำลังมากๆ ",
			"Reuse",
			"ใช้ปุ๋ยเคมีในปริมาณมากเพื่อบำรุงดิน",
			"การซักผ้าในน้ำเย็น",
			"มีเทน",
			"มีเทน",
			"มลพิษทางอากาศเพิ่มขึ้น ",
			"มีการผลิตเครื่องจักรไอน้ำ ",
			"การผลิตทางอุตสาหกรรม ",
			"เบิร์ด เปิดพัดลมแทนเครื่องปรับอากาศ",
			"ระดับน้ำทะเลสูงขึ้น ",
			"ใช้ทรัพยากรอย่างประหยัด",
			"ดวงใจเผาวัชพืชที่ขึ้นบนที่ดินของตนจนหมด ",
			"เป็นสารก่อมะเร็ง ",
			"ลงโทษผู้ฝ่าฝืนลักลอบตัดไม้อย่างเคร่งครัด ",
			"ยกเลิกการสัมปทานป่าไม้ ",
			"เป็น เพราะป่าไม้เป็นแหล่งต้นน้ำลำธาร ",
			"นำกระดาษที่ใช้แล้วหน้าเดียวกลับมาใช้อีก "

	};

	const std::string *answer2Title = new std::string[25]{
			"การหาแหล่งน้ำใหม่ไว้ใช้เพิ่มเติม",
			"การกระทำของมนุษย์ ",
			"ไม่ตัดไม้ทำลายป่า",
			"คาร์บอนไดออกไซด์ ,co ,CFCs",
			"รังสีอินฟาเรดและรังสีอัลตราไวโอเลต ",
			"จากการเผาไหม้เชื้อเพลิงของโรงงานอุตสาหกรรมต่างๆ",
			"ทำให้ระดับน้ำทะเลทางขั้วโลกเหนือเพิ่มขึ้น",
			"ใช้เครื่องยนต์ที่มีการเผาไหม้อย่างสมบูรณ์ ",
			"Recycle",
			"ปลูกพืชหมุนเวียนจากพวกพืชตระกูลถั่ว",
			"ลดขยะของบ้านคุณให้ได้ครึ่งหนึ่ง ",
			"คาร์บอนไดออกไซด์",
			"ซีเอฟซี ",
			"สภาพอากาศแปรปรวน",
			"มีการขยายตัวทางอุตสาหกรรม ",
			"การเกษตร",
			"บัส ปลูกต้นไม้รอบๆบ้าน",
			"เกิดพายุน้อยลง",
			"ใช้สิ่งอื่นทดแทนทรัพยากรธรรมชาติที่หายาก",
			"สุเทพถอนวัชพืชออกจากไร่จนหมดแล้วนำไปฝัง",
			"ทำให้ระคายเคืองตา",
			"ใช้ไม้และผลผลิตจากป่าไม้ให้เกิดประโยชน์สูงสุด ",
			"ปลูกป่าเพิ่มเท่าที่ตัดต้นไม้ไปใช้ ",
			"เป็น เพราะวัฏจักรของน้ำจะเกิดขึ้นได้ เมื่อมีป่าไม้เท่านั้น",
			"งดการใช้รถยนต์ที่เติมน้ำมันหรือแก๊สธรรมชาติ "

	};

	const std::string *answer3Title = new std::string[25]{
			"การขุดบ่อเก็บน้ำไว้ใช้ยามขาดแคลน",
			"การใช้พลังงานมากเกินไป",
			"ลดการเผาไหม้เชื้อเพลิงต่างๆ",
			"คาร์บอนไดออกไซด์ ,CFCs ,ไนตรัสออกไซด์ ",
			"รังสีอินฟาเรดและรังสียูวี",
			"การตัดไม้ทำลายป่า",
			"เกิดความแห้งแล้งในฤดูร้อนที่ยาวนาน",
			"ใช้น้ำมันไร้สารตะกั่วและทำความสะอาดเครื่องยนต์อยู่เสมอ",
			"Repair",
			"ปลูกพืชแบบขั้นบันไดในพื้นที่ลาดชัน",
			"การเปลี่ยนหลอดไฟเป็นหลอดฟลูออเรสเซนต์",
			"ไนตรัสออกไซด์",
			"คาร์บอนไดออกไซด์",
			"ปริมาณน้ำในมหาสมุทรเพิ่มขึ้น",
			"จำนวนประชากรเพิ่มขั้น ",
			"ป่าไม้ ",
			"เกด ใช้จักรยานแทนรถยนต์ ",
			"คลื่นความร้อนบ่อยขึ้น",
			"ปรับปรุงทรัพยากรในท้องถิ่นให้มีสภาพที่ดีขึ้น",
			"สมร ปลูกข้าวโพดติดต่อกัน10ปีบนพื้นที่เดียวกัน ",
			"มีฤทธิ์กัดกร่อนเยื่อบุโพรงจมูก ",
			"เผยแพร่ความรู้เกี่ยวกับผลเสียของการตัดไม้ทำลายป่า",
			"กำหนดเขตป่าสงวนเอาไว้ให้มากที่สุด",
			"ไม่เป็น เพราะป่าไม้กับแหล่งน้ำลำธารไม่ได้มีส่วนเกี่ยวข้องกันเลย",
			"งดปลูกพืชในบริเวณที่ดินเสื่อมคุณภาพไปแล้ว"

	};

	const std::string *answer4Title = new std::string[25]{
			"การนำเทคโนโลยีใหม่ๆมาใช้ในการบำบัดน้ำเสีย",
			"การเปลี่ยนแปลงของสภาพภูมิอากาศ ",
			"การสลายตัวของอินทรีย์วัตถุ ",
			"คาร์บอนไดออกไซด์ ,ออกซิเจน ,ไนตรัสออกไซด์ ",
			"รังสียูวีและรังสีเอ็กซ์ ",
			"จากการย่อยสลายของสิ่งมีชีวิต ",
			"ทำให้เชื้อโรคเจริญเติบโตอย่างรวดเร็ว ",
			"ใช้เครื่องยนต์ที่มีการติดตั้งเครื่องสำหรับเปลี่ยนไอเสียเป็นไนโตรเจน",
			"Remove",
			"การปลูกหญ้าแฝกเพื่อป้องกันการพังทลายของดิน",
			"หลีกเลี่ยงผลิตภัณฑ์ที่มีบรรจุภัณฑ์เยอะ",
			"ซัลเฟอร์ไดออกไซด์",
			"ไนตัสออกไซด์",
			"น้ำแข็งบริเวณขั้วโลกละลาย",
			"ป่าไม้ถูกทำลายมากขึ้น",
			"พลังงาน",
			"แพรว อาบน้ำเย็นแทนอุ่น",
			"ปัญหาภัยแล้งกำลังจะหมดไปเพราะน้ำท่วม",
			"ซื้อทรัพยากรที่หายากกักตุนไว้",
			"สุยต้องการให้พืชผักที่ตนปลูกสวยงามจึงใช้ยาฆ่าแมลงจำนวนมาก",
			"ขัดขวางการขนส่งออกซิเจนของเม็ดเลือดแดง ",
			"ให้การศึกษาอบรมแก่เยาวชน เพื่อสร้างจิตสำนึกในการอนุรักษ์ป่าไม้ ",
			"เลือกตัดต้นไม้เฉพาะที่จำเป็นหรือใช้ประโยชน์ได้ ",
			"ไม่เป็น เพราะสามารถสร้างเขื่อนกักเก็บน้ำไว้ใช้ในยามขาดแคลนได้ ",
			"กำจัดขยะจากชุมชนโดยการเผาในเตาเผาขยะทุกวัน"
	};

	int *questionAnswer = new int[25]{0, 1, 0, 2, 1, 3, 0, 2, 3, 0, 1, 2, 1, 0, 1, 0, 2, 0, 3, 1, 3, 3, 3, 0, 0};

	sceneContainer->append(new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE}));

	auto gameC = sceneContainer->append(new ImageView(SDLRendererController, gameTrue, 10, {300, 300}, {10, 120, POSITION_RELATIVE}));
	auto gameX = sceneContainer->append(new ImageView(SDLRendererController, gameFalse, 10, {350, 350}, {1275, 50, POSITION_RELATIVE}));

	for (int i = 0; i < 25; i++) {
		questions[i].Q = sceneContainer->append(new Button(SDLRendererController,
		                                                   (std::string &&) questionTitle[i],
		                                                   {45, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
		                                                    {0, 0, 0}},
		                                                   kob1, doNothing(),
		                                                   16, {1100, 400}, {270, 20, POSITION_ABSOLUTE}));
		ComponentSize textSize = questions[i].Q->getTextView()->getSize();
		questions[i].Q->getTextView()->setPosition({(questions[i].Q->getSize().width - textSize.width) / 2,
		                                            (questions[i].Q->getSize().height - textSize.height) / 2 + 50});
		questions[i].A[0] = sceneContainer->append(new Button(SDLRendererController,
		                                                      (std::string &&) answer1Title[i],
		                                                      {25, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
		                                                       {0, 0, 0}},
		                                                      kob2, doNothing(),
		                                                      16, {545, 150}, {300, 450, POSITION_ABSOLUTE}));
		questions[i].A[1] = sceneContainer->append(new Button(SDLRendererController,
		                                                      (std::string &&) answer2Title[i],
		                                                      {25, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
		                                                       {0, 0, 0}},
		                                                      kob2, doNothing(),
		                                                      16, {545, 150}, {1000, 450, POSITION_ABSOLUTE}));
		questions[i].A[2] = sceneContainer->append(new Button(SDLRendererController,
		                                                      (std::string &&) answer3Title[i],
		                                                      {25, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
		                                                       {0, 0, 0}},
		                                                      kob2, doNothing(),
		                                                      16, {545, 150}, {300, 650, POSITION_ABSOLUTE}));
		questions[i].A[3] = sceneContainer->append(new Button(SDLRendererController,
		                                                      (std::string &&) answer4Title[i],
		                                                      {25, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
		                                                       {0, 0, 0}},
		                                                      kob2, doNothing(),
		                                                      16, {545, 150}, {1000, 650, POSITION_ABSOLUTE}));
	}

	auto A = new (Button *);
	auto B = new (Button *);
	auto C = new (Button *);
	auto D = new (Button *);

	int *questionNumber = new int{0};
	auto showNewQuestion = [=]() mutable {
		srand(time(nullptr));

		for (int i = 0; i < 25; i++) {
			questions[i].Q->show(false);
			questions[i].A[0]->show(false);
			questions[i].A[1]->show(false);
			questions[i].A[2]->show(false);
			questions[i].A[3]->show(false);
		}
		answer[0] = false;
		answer[1] = false;
		answer[2] = false;
		answer[3] = false;

		questions[*questionNumber].Q->show(true);
		questions[*questionNumber].A[0]->show(true);
		questions[*questionNumber].A[1]->show(true);
		questions[*questionNumber].A[2]->show(true);
		questions[*questionNumber].A[3]->show(true);
		answer[questionAnswer[*questionNumber]] = true;

		(*questionNumber)++;
	};

	auto backToMenu = sceneContainer->append(new Button(SDLRendererController,
	                                                    "MENU", {40, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
	                                                             {0, 0, 0}},
	                                                    box,
	                                                    [=](Touchable *button, ComponentPosition clickPosition,
	                                                        SDL_Event event) mutable {
		                                                    gameScenes->setCurrentSceneName("menu");
	                                                    },
	                                                    16, {200, 75}, {1400, 20, POSITION_ABSOLUTE}))->show(false);

	auto boxEnd = sceneContainer->append(new Button(SDLRendererController,
	                                                "Your score = 0",
	                                                {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
	                                                 {0, 0, 0}},
	                                                box, doNothing(),
	                                                50, {800, 125}, {-85, 10, POSITION_ABSOLUTE}));
	ComponentSize textSize = boxEnd->getTextView()->getSize();
	boxEnd->getTextView()->setPosition({(boxEnd->getSize().width - textSize.width) / 2 - 55,
	                                    (boxEnd->getSize().height - textSize.height) / 2});

	std::function<std::function<void(Touchable *, ComponentPosition, SDL_Event)>(int)> getAnsHandler = [=](int index)mutable {
		return [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) mutable {
			if (*answering) return;
			*answering = true;
			auto result = answer[index] ? gameC : gameX;
			*score += answer[index] ? 100 : 0;
			result->show(true);
			timer->setTimeout([=]() mutable {
				result->show(false);
				*answering = false;
				if (*questionNumber < 25) {
					showNewQuestion();
				} else {
					backToMenu->show(true);
					(*A)->show(false);
					(*B)->show(false);
					(*C)->show(false);
					(*D)->show(false);
					boxEnd->setPosition({400, 400, POSITION_ABSOLUTE});
					for (int i = 0; i < 25; i++) {
						questions[i].Q->show(false);
						questions[i].A[0]->show(false);
						questions[i].A[1]->show(false);
						questions[i].A[2]->show(false);
						questions[i].A[3]->show(false);
					}
				}
			}, 1000);
			boxEnd->getTextView()->changeText("Your score = " + std::to_string(*score));
		};
	};

	*A = sceneContainer->append(new Button(SDLRendererController,
	                                       "A", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
	                                             {0, 0, 0}},
	                                       box, getAnsHandler(0),
	                                       10, {175, 125}, {150, 465, POSITION_ABSOLUTE}));
	*B = sceneContainer->append(new Button(SDLRendererController,
	                                       "B", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
	                                             {0, 0, 0}},
	                                       box, getAnsHandler(1),
	                                       10, {175, 125}, {850, 465, POSITION_ABSOLUTE}));
	*C = sceneContainer->append(new Button(SDLRendererController,
	                                       "C", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
	                                             {0, 0, 0}},
	                                       box, getAnsHandler(2),
	                                       10, {175, 125}, {150, 665, POSITION_ABSOLUTE}));
	*D = sceneContainer->append(new Button(SDLRendererController,
	                                       "D", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
	                                             {0, 0, 0}},
	                                       box, getAnsHandler(3),
	                                       10, {175, 125}, {850, 665, POSITION_ABSOLUTE}));

	scene->onEnterScene([=](Scene *scene) mutable {
		gameC->show(false);
		gameX->show(false);

		for (int i = 0; i < 25; i++) {
			questions[i].Q->show(false);
			questions[i].A[0]->show(false);
			questions[i].A[1]->show(false);
			questions[i].A[2]->show(false);
			questions[i].A[3]->show(false);
		}

		showNewQuestion();
	});
}
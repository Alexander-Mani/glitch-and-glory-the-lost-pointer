#include "StoryHandler.h"

const std::string StoryHandler::PRE_INTRO = "The year is 2089 Reykjavik is not the city it once was...";

const std::string StoryHandler::INTRO_CONTENT_1 = R"(
Samherji PMC squads patrol the streets around the mega-skyscrapers of Borgartún, 
armed with high-tech combat HUDs, katanas, and railguns.

You lead a squad of three mercenaries—outcasts with no ties to the corporations, 
loyal only to the highest bidder—or, in this case, to a promise.

The last free workers in Iceland, a commune of fishermen, once struck a deal with Samherji 
for fair wages and protections. Instead, the corporation deployed automated trawlers and armed patrols, 
driving them from their own waters. Now, they barely survive in the underground markets, 
their only hope resting on those willing to strike back.

That’s where you come in.
)";

const std::string StoryHandler::INTRO_MISSION = R"(

The Mission

Your crew has been hired to recover the lost wages—but the Eddies($) aren’t just sitting in a vault. 
They've been minted onto a blockchain pointer, locked within the neural interface of Samherji’s CEO. 
To complete your contract, you’ll have to fight him and extract the data straight from his brain.
)";

const std::string StoryHandler::HOW_TO_PLAY = R"(
HOW TO PLAY

* Go to the Arena to earn xp and money.
* Go To the shop and ripper to buy equipment.
* Go to apartments when your party is low on hp.
* Once you think you are powerful enough, attempt to take on the boss in HQ 
)";

// Phase 1 - Human Elontron
const std::string StoryHandler::ELON_ATMO_1 = R"(
(Elontron stands tall, a man augmented beyond recognition, eyes glowing with neural data streams.)
Elontron:
)";

const std::string StoryHandler::ELON_DIALOGUE_1 = R"(
"So, the rats finally crawl out of the sewers. Mercenaries, rebels, scavengers—you’re all the same. 
You think you can steal from me? From Samherji? You don’t even understand what you’re meddling with."
)";

const std::string StoryHandler::ELON_ATMO_2 = "(He gestures, activating an energy blade at his wrist.)\n";

// Phase 2 - Elontron Prime (Starship Form)
const std::string StoryHandler::ELON_ATMO_3 = "(Elontron stumbles back, his body failing. He chuckles—distorted, digital, inhuman.)\n";

const std::string StoryHandler::ELON_DIALOGUE_2 = R"("Did you really think you were fighting me? Flesh is a liability. 
I left that behind long ago."
)";

const std::string StoryHandler::ELON_ATMO_4 = R"(
(His body collapses, sparking. A deep hum fills the air. The walls tremble. 
The roof splits open—above, descending from the sky, looms a colossal starship, 
its metallic plating shifting into the form of a towering robotic construct.)
)";

const std::string StoryHandler::ELON_DIALOGUE_3 = R"(
"I am beyond humanity now. I am beyond you. 
I am Elontron Prime—a vessel of thought, a mind unshackled by weakness. 
This is your last mistake"
)";

// Final Lore Dump
const std::string StoryHandler::FINAL_LORE_DUMP = R"(
(The remains of Elontron Prime smolder. Sparks flicker in the ruined husk of what was once the most powerful entity in Samherji’s empire. The neural core—still pulsing—lays exposed. The lost pointer is within reach.)

Your crew’s hacker extracts the pointer, decrypting its payload. The truth unravels before you like a virus spreading through the network…

The Rise of Samherji’s Digital Tyranny
The Eddies($) weren’t just wages. They were proof—irrefutable proof—that Samherji had been laundering billions through black-market neural exchanges, funneling stolen wealth into secret off-world colonies.

The fishermen’s wages? Just a fraction of what had been siphoned. When the workers resisted, they weren’t just cast aside—they were erased, their biometric data scrubbed from the system, rendering them legally nonexistent.

And Elontron? He hadn’t transferred his consciousness into the starship. He’d been forced into it. His mind had become the final failsafe—locked inside an immortal, corporate-owned war machine, designed to think only in profit and preservation.
)";



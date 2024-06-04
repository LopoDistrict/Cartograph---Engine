const audio4 = new Audio(`./audio/menu_selection.wav`);
                            audio4.play();
                            
                    

                    const { exec } = require('child_process');
                    const { shell } = require('electron');

                        function launchExe() {
                        // Replace 'path/to/your/executable.exe' with the actual path to your .exe file
                        exec('inventory.exe', (error, stdout, stderr) => {
                            if (error) {
                            console.error(`Error launching .exe file: ${error.message}`);
                            } else {
                            console.log(`.exe file launched successfully: ${stdout}`);
                            transitionToPage('inventory.html')
                            
                            }
                        });
                        }

                        function launchEquip(){
                            exec('Equip.exe', (error, stdout, stderr) => {
                            if (error) {
                            console.error(`Error launching .exe file: ${error.message}`);
                            } else {
                            console.log(`.exe file launched successfully: ${stdout}`);
                            
                            document.getElementById("equip_hidden").style.display = "block";
                            
                            }
                        });
                        }

                        window.transitionToPage = function(href) {
                        document.querySelector('body').style.opacity = 0
                        setTimeout(function() { 
                            const audio4 = new Audio(`./audio/menu_selection.wav`);
                            audio4.play();
                            window.location.href = href
                        }, 500)
                    }

                    document.addEventListener('DOMContentLoaded', function(event) {
                        document.querySelector('body').style.opacity = 1
                    })

                    
                    const fs = require('fs');
                    const jsonData = JSON.parse(fs.readFile(__dirname+ '/json/player_stats.json', 'utf8'));
                     for (let i of jsonData.Stats) {
                             player_name = i.name;
                             player_life = i.health;
                             player_dmg = i.av_dmg;
                             player_def = i.defense;
                             player_id = i.id;
                             player_level = i.level;
                             player_exp = i.experience;
                             player_faction = i.faction;
                             player_money = i.money;
                             break;                           
                     }
                     
                 document.getElementById("dmg").innerHTML ="Average Damage: " + player_dmg;
                 document.getElementById("name").innerHTML ="name: "+player_name;
                 document.getElementById("player_id").innerHTML ="Player Id: "+player_id;
                 document.getElementById("def").innerHTML ="Defense: "+player_def;
                 document.getElementById("life").innerHTML ="Health: "+player_life;
                 document.getElementById("lvl").innerHTML ="level: "+player_level;
                 document.getElementById("xp").innerHTML ="experience: "+player_exp;
                 document.getElementById("money").innerHTML ="money: "+player_money + "$";
                 document.getElementById("faction").innerHTML ="faction: "+player_faction;
                     
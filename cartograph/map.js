function show_popup(id) {
    
    var fileHtmlWindow = window.parent;

    // Send a message to file.html to show the popup
    fileHtmlWindow.postMessage(id, '*');
}

function collecting(type){
    var fileHtmlWindow = window.parent;
    fileHtmlWindow.postMessage(type, '*');
}

function dungeon(dungeon_id){
    var fileHtmlWindow = window.parent;
    fileHtmlWindow.postMessage(dungeon_id, '*');   
}

function open_shop(arg){
    var fileHtmlWindow = window.parent;
    fileHtmlWindow.postMessage(arg, '*');
}

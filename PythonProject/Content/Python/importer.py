import unreal
from PySide6.QtWidgets import *
from PySide6.QtCore import *

class starting_ue(QWidget):

    path_key = "fbx_from_path"


    def __init__(self):
        super().__init__()
        self.init_settings()
        self.setWindowTitle("UE-FBX-Importer")
        self.draw_ui()
        self.reload_save()
        self.bind_ui()

    def init_settings(self):
        self.save_settings = QSettings("O3D-P2", "UE-FBX-Importer")

    def reload_save(self):
         ##UNITY => PLayerPref.Set...(string, int, float)
         self.path = self.save_settings.value(self.path_key)
         self.fbx_path.setText("Path : {0}".format(self.path))
         self.read_directory(self.path)


    def draw_ui(self):
        self.setMinimumWidth(280)
        self.layout = QVBoxLayout(self)

        self.btn_form = QPushButton("Select FBS folder")
        self.make_content_folder_btn = QPushButton("Prepare project Directory")
        self.drop_btn = QPushButton("Drop files into project")
        self.fbx_path = QLabel("Path : ")
        self.fbx_list = QListWidget()
        self.fbx_list.setSelectionMode(QAbstractItemView.SelectionMode.MultiSelection)

        self.layout.addWidget(self.btn_form)
        self.layout.addWidget(self.fbx_path)
        self.layout.addWidget(self.make_content_folder_btn)
        self.layout.addWidget(self.fbx_list)
        self.layout.addWidget(self.drop_btn)


    def bind_ui(self):
        self.btn_form.clicked.connect(self.open_browse)
        self.make_content_folder_btn.clicked.connect(self.prepare_project_directory)
        self.fbx_list.itemClicked.connect(self.update_ui)
        self.drop_btn.clicked.connect(self.drop_items)

    def open_browse(self):
        self.path = QFileDialog.getExistingDirectory(self, "Select Directory")
        self.save_settings.setValue(self.path_key, self.path)
        self.fbx_path.setText("Path : {0}".format(self.path))
        self.read_directory(self.path)

    def prepare_project_directory(self):
        unreal.EditorAssetLibrary.make_directory("/Game/FBX")

    def read_directory(self, path):
        folder = QDir(path)
        self.fbx_list.clear()
        self.files = folder.entryList(["*.fbx"], QDir.Files)
        for f in self.files:
            self.fbx_list.addItem(f)
        self.drop_btn.setText("Drop {0} files into projects".format(len(self.fbx_list.selectedItems())))

    def update_ui(self):
        self.drop_btn.setText("Drop {0} files into projects".format(len(self.fbx_list.selectedItems())))

    def drop_items(self):
        #unreal.EditorAssetLibrary.does_directory_exist() //pour savoir si un folder existe
        files_to_load = []
        if len(self.fbx_list.selectedItems()) == 0:
            files_to_load = self.files
        else :
            for f in self.fbx_list.selectedItems():
                files_to_load.append(f.text())
        self.prepare_project_directory()
        tasks = []
        for f in files_to_load:
            destination_path = "{0}".format("/Game/FBX")
            filename = "{0}/{1}".format(self.path, f)
            valid_destination_filename = "FBX_{0}".format(f)
            options = unreal.FbxImportUI()
            options.import_mesh = True
            options.import_textures = False
            options.import_materials = False
            options.import_as_skeletal = False
            data = unreal.FbxStaticMeshImportData()
            data.combine_meshes = True
            options.static_mesh_import_data = data
            task = unreal.AssetImportTask()
            task.set_editor_property('automated', True)
            task.set_editor_property('destination_name', valid_destination_filename)
            task.set_editor_property('destination_path', destination_path)
            task.set_editor_property('filename', filename)
            task.set_editor_property('replace_existing', True)
            task.set_editor_property('save', True)
            task.set_editor_property('options', options)
            tasks.append(task)
        unreal.AssetToolsHelpers.get_asset_tools().import_asset_tasks(tasks)
########



main = None
if not QApplication.instance(): 
    main = QApplication()
else:
    main = QApplication.instance()



app = starting_ue()
app.show()
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafx_offline;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.Scanner;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.FileChooser;

/**
 *
 * @author HP
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private TextField location;
    @FXML
    private TableView<WordDetails> resultView;
    @FXML
    private TableColumn<WordDetails, String> word;
    @FXML
    private TableColumn<WordDetails, Integer> frequency;
    
    ObservableList<WordDetails>list = FXCollections.observableArrayList();
    
    
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        resultView.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
        
        word.setCellValueFactory(new PropertyValueFactory<WordDetails,String>("word"));
        frequency.setCellValueFactory(new PropertyValueFactory<WordDetails,Integer>("frequency"));
        //salary.setCellValueFactory(new PropertyValueFactory<Person,Double>("salary"));
        
        resultView.setItems(list);
    }    

    @FXML
    private void chooseFileAction(ActionEvent event) {
        
        FileChooser filechooser = new FileChooser();
        File file = filechooser.showOpenDialog(null);
        
        if(file==null) return;
        
        location.setText(file.toString());
    }

    @FXML
    private void resultButtonAction(ActionEvent event) throws FileNotFoundException {
        
        int c=1,k=0;
        int ara[];
        
        File file = new File(location.getText());
        
        Scanner sc = new Scanner(file);
        
        //String str[] = new String[1000];
        
        String s = "";
        //String str = "";
        
        while(sc.hasNext()){
            s+=sc.next()+" ";
        }
        
        //System.out.println(s);
        
        String [] parts = s.split("[\\W]+");
        
        ara = new int[parts.length];
        
        //System.out.println(parts.length);
        
        for(int i=0;i<parts.length;i++){
            for(int j=i+1;j<parts.length;j++){
                if(!parts[i].equals(" ")){
                   if(parts[i].equals(parts[j])){
                    parts[j]=" ";
                    c++;
                   }
                }
            }
            ara[k] = c;
            k++;
            c=1;
        }
        
        k=0;
        
        for (String part : parts) {
            if (!part.equals(" ")) {
                //System.out.println(parts[i]+"   "+ara[k]);
                //k++;
                 WordDetails w_details = new WordDetails(part, ara[k]);
                 list.add(w_details);
                 k++;
            }
        }
    }
    
}
